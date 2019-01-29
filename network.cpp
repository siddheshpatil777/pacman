#include "network.h"
int Network::tcp_clients;
sf::Int64 Network::tick;
sf::IpAddress Network::everyone;
sf::Packet Network::main_packet;
sf::TcpListener Network::listener;
bool Network::all_textures_loaded;
sf::IpAddress Network::host;
sf::UdpSocket Network::socket; 
Array<sf::IpAddress> Network::clients_address;
unsigned int Network::udp_port=9999;
unsigned int Network::tcp_port=55001;
Array<sf::Texture*> Network::textures;
Array<sf::TcpSocket>Network::clients;
sf::Texture *Network::background;
ToDraw Network::todraw;
Array<ToDraw> Network::main_data;
sf::SocketSelector Network::selector;
//
sf::Thread Network::thread_askClient(&askClient);
sf::Thread Network::thread_checkForIncomingConnections(&checkForIncomingConnections);
sf::Thread Network::thread_sendAllTexturesToClient(&sendAllTexturesToClient);
//
sf::TcpSocket Network::client;
//
sf::Packet&operator <<(sf::Packet& packet,const sf::Vector2u &vec){
	packet<<vec.x<<vec.y;
}
sf::Packet&operator <<(sf::Packet& packet,const sf::Vector2f &vec){
	packet<<vec.x<<vec.y;
}
sf::Packet&operator <<(sf::Packet& packet,const sf::Color &color){
	packet<<color.r<<color.g<<color.b<<color.a;
}

sf::Packet&operator <<(sf::Packet& packet,const sf::Image &image){
	sf::Vector2u dim(image.getSize());
	packet<<dim;
//	long long int size=4*image.getSize().x*image.getSize().y;
	//Uint8 *data=; 
	for(int i=0;i<dim.y;i++){
		for(int j=0;j<dim.x;j++){
			packet<<image.getPixel(j,i); 
		}
	} 
}
sf::Packet&operator <<(sf::Packet& packet,const ToDraw &t){
	packet<<t.id<<t.pos;
}
////
void Network::setupEverythingForNetwork(){
	cout<<"UdpSocket::MaxDatagramSize ="<< sf::UdpSocket::MaxDatagramSize<<"\n";
	host=sf::IpAddress::getLocalAddress();
	listener.listen(tcp_port);
	cout<<"udp socket status = "<<socket.bind(udp_port,sf::IpAddress::getLocalAddress())<<"\n";
//	socket.setBlocking(false);
	tcp_clients=0;
	clients.setLength(MAX_CLIENTS);
	clients_address.setLength(MAX_CLIENTS);
	textures.setLength(MAX_IMAGES);
	tick=0;
	everyone=sf::IpAddress::Broadcast;
	main_data.setLength(MAX_TO_DRAW_ELEMENTS);
	selector.add(listener);
	//bb  thread=sf::Thread(&loop);
}
void Network::destroyEverythingForNetwork(){
	socket.unbind();	
}
void Network::checkForIncomingConnections(){
	//sf::Thread thread(&loop);
	//thread.launch();
	while(true){
		if(selector.wait()){
			if (selector.isReady(listener)){
			//	sf::TcpSocket *client=new sf::TcpSocket;
				if (listener.accept(client) == sf::Socket::Done){
					thread_askClient.launch();
					break;
				}
			//	delete client;
			}
		}
	}
}
void Network::startMainThread(){
	thread_checkForIncomingConnections.launch();
}
void Network::askClient(){
  //  if (listener.accept(clients[tcp_clients]) == sf::Socket::Done){
    	sf::Mutex mutex;
    	mutex.lock();
		tcp_clients++;	
		clients_address.push(client.getRemoteAddress());
		mutex.unlock();
        std::cout << "New connection received from " << client.getRemoteAddress() << std::endl;
	    thread_sendAllTexturesToClient.launch();

}
void Network::sendAllTexturesToClient(){
	sf::Image temp;
	sf::Packet packet;
	packet<<"SENDING_TEXTURE_DATA_STARTED";
	client.send(packet);
	packet.clear();
	packet<<textures.length();
	client.send(packet);
	packet.clear();
	temp=background->copyToImage();
	packet<<temp;
	client.send(packet);
	for(int i=0;i<textures.length();i++){
		packet.clear();
		temp=textures[i]->copyToImage();
		packet<<temp;
		client.send(packet);
	}
	client.disconnect();
	//packet<<"SENDING_TEXTURE_DATA_ENDED";	
}
void Network::draw(const int &id,const sf::Vector2f &pos){
	//
	main_packet.clear();
	//sf::Packet p;
	ToDraw t;
	t.pos=pos;
	t.id=id;
	//cout<<"id ="<<id<<"\n";
	//p<<"DRAW"<<t;
	//
	main_packet<<t;
//	char data[100]={"12367890"};
//	main_packet<<data;
	sendMainPacketToEveryone(main_packet);
	//cout<<"send status "<<socket.send(data,sizeof(data),sf::IpAddress::Broadcast,udp_port)<<"\n";
}
void Network::sendMainPacketToEveryone(sf::Packet &packet){
//	cout<<"entered send func"<<"\n";
	cout<<"send status "<<socket.send(packet,sf::IpAddress::Broadcast,udp_port)<<"\n";
//	cout<<"data sent"<<"\n";
	//main_data.clear();
}
void Network::display(){
	main_packet.clear();
	ToDraw t;
	t.id=-1;
	t.pos=sf::Vector2f(0.0,0.0);
	main_packet<<t;
	sendMainPacketToEveryone(main_packet);
}
void Network::setPort(unsigned int _port){
	//port=_port;
}
void Network::registerThisTexture( sf::Texture &texture){
	textures.push(&texture);	
}
void Network::registerThisTexture( sf::Texture *texture){
	textures.push(texture);
}
void registerThisImage(const sf::Image &image){
	
}
void Network::registerBackground(sf::Texture *texture){
 	background=texture;
 }


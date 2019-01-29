#ifndef NETWORK_H
#define NETWORK_H
#include "todraw.h"
#include "main_defines.h"
#include "MYCLASSES/array.h"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
class Network{
	static sf::SocketSelector selector;
	//
	static sf::Thread thread_askClient;
	static sf::Thread thread_checkForIncomingConnections;
	static sf::Thread thread_sendAllTexturesToClient;
	//
	static sf::TcpSocket client;
	//
	static sf::Int64 tick;
	static int tcp_clients;
	static sf::TcpListener listener;
	static bool all_textures_loaded;
	static unsigned int udp_port;
	static unsigned int tcp_port;
	static sf::Texture *background;
	static sf::IpAddress host;
	static sf::UdpSocket socket; 
	static Array<sf::TcpSocket>clients;
	static sf::IpAddress everyone;
	static Array<sf::IpAddress>clients_address;
	static Array<sf::Texture*>textures;
	static void sendAllTexturesToClient();
	static sf::Packet main_packet;
	static ToDraw todraw;
	static Array<ToDraw> main_data;
	static void askClient();
	static void checkForIncomingConnections();
	public:
		//static void prepare
		static void sendMainPacketToEveryone(sf::Packet &packet);
		static void startMainThread();
		static void setPort(unsigned int _port);
		static void registerBackground(sf::Texture *texture);
		static void registerThisTexture( sf::Texture &texture);
		static void registerThisTexture( sf::Texture *texture);
		static void registerThisImage(const sf::Image &image);
		static void draw(const int &id,const sf::Vector2f &pos);
		static void display();
		static void setupEverythingForNetwork();
		static void destroyEverythingForNetwork();
};

#endif

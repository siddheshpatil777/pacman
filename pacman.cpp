#include "pacman.h"
Pacman *Pacman::pacmans;
int Pacman::pacmans_length;
sf::RenderTexture Pacman::pacman_screen_layer;
sf::Sprite Pacman::pacman_screen_tile; 
int* Pacman::textures_main;
sf::Texture *Pacman::all_sprites;
int Pacman::textures_length;
//Array<int> Pacman::textures_main;
//sf::Texture *Pacman::all_sprites;
//Dictionary<sf::Vector2i> Pacman::sprites_pos(20);
Pacman::Pacman():Character(){
	justDied=false;
}

void Pacman::loadAllSpritesFromFile(){
	/*
	//int a;
	textures_main.push(pacmans[0].world->responseToRequestForTile(sf::Vector2i(0,0)));
//	Network::registerThisTexture(all_sprites[textures_main[-1]]);
	textures_main.push(pacmans[0].world->responseToRequestForTile(sf::Vector2i(1,0)));
//	Network::registerThisTexture(all_sprites[textures_main[-1]]);
	textures_main.push(pacmans[0].world->responseToRequestForTile(sf::Vector2i(0,1)));
//	Network::registerThisTexture(all_sprites[textures_main[-1]]);
	textures_main.push(pacmans[0].world->responseToRequestForTile(sf::Vector2i(1,1)));
//	Network::registerThisTexture(all_sprites[textures_main[-1]]);
	textures_main.push(pacmans[0].world->responseToRequestForTile(sf::Vector2i(0,2)));
//	Network::registerThisTexture(all_sprites[textures_main[-1]]);
	textures_main.push(pacmans[0].world->responseToRequestForTile(sf::Vector2i(1,2)));
//	Network::registerThisTexture(all_sprites[textures_main[-1]]);
	textures_main.push(pacmans[0].world->responseToRequestForTile(sf::Vector2i(0,3)));
//	Network::registerThisTexture(all_sprites[textures_main[-1]]);
	textures_main.push(pacmans[0].world->responseToRequestForTile(sf::Vector2i(1,3)));
//	Network::registerThisTexture(all_sprites[textures_main[-1]]);
	*/
	//int a;
	
	textures_main[textures_length++]=pacmans[0].world->responseToRequestForTile(sf::Vector2i(0,0));
	textures_main[textures_length++]=pacmans[0].world->responseToRequestForTile(sf::Vector2i(1,0));
	textures_main[textures_length++]=pacmans[0].world->responseToRequestForTile(sf::Vector2i(0,1));
	textures_main[textures_length++]=pacmans[0].world->responseToRequestForTile(sf::Vector2i(1,1));
	textures_main[textures_length++]=pacmans[0].world->responseToRequestForTile(sf::Vector2i(0,2));
	textures_main[textures_length++]=pacmans[0].world->responseToRequestForTile(sf::Vector2i(1,2));
	textures_main[textures_length++]=pacmans[0].world->responseToRequestForTile(sf::Vector2i(0,3));
	textures_main[textures_length++]=pacmans[0].world->responseToRequestForTile(sf::Vector2i(1,3));
	//directional/
	for(int i=0;i<11;i++){
		textures_main[textures_length++]=pacmans[0].world->responseToRequestForTile(sf::Vector2i(2+i,0));
//		Network::registerThisTexture(all_sprites[textures_main[-1]]);
	}
}
void Pacman::set(sf::RenderWindow *_window,World *_world){
	if(!pacman_screen_layer.create(448,576)){
		cout<<"Error while creating  PACMAN texture "<<"\n";
	}
	else{
		cout<<"succesfully  created PACMAN screen texture "<<"\n";
	}
	setImportantVariables(_window,_world);
	cout<<"PACMAN CREATED "<<"\n";	
	char t[20]={"PACMAN"};
	hitbox.setType(t);	
	id=pacmans_length;
	width=32;
}
void Pacman::draw(){
	main_sprite.setPosition(pos.x-TILE_SIZE,pos.y-TILE_SIZE);
	if(direction==UP){
		main_sprite.setTexture(all_sprites[textures_main[TILE_UP_1+int(switchting_variable)]]);
//		Network::draw(textures_main[TILE_UP_1+int(switchting_variable)],sf::Vector2f(pos.x-TILE_SIZE,pos.y-TILE_SIZE));
	}
	else if(direction==LEFT){
		main_sprite.setTexture(all_sprites[textures_main[TILE_LEFT_1+int(switchting_variable)]]);
//		Network::draw(textures_main[TILE_LEFT_1+int(switchting_variable)],sf::Vector2f(pos.x-TILE_SIZE,pos.y-TILE_SIZE));
	}
	else if(direction==RIGHT){
		main_sprite.setTexture(all_sprites[textures_main[TILE_RIGHT_1+int(switchting_variable)]]);
//		Network::draw(textures_main[TILE_RIGHT_1+int(switchting_variable)],sf::Vector2f(pos.x-TILE_SIZE,pos.y-TILE_SIZE));
	}
	else if(direction==DOWN){
		main_sprite.setTexture(all_sprites[textures_main[TILE_DOWN_1+int(switchting_variable)]]);	
//		Network::draw(textures_main[TILE_DOWN_1+int(switchting_variable)],sf::Vector2f(pos.x-TILE_SIZE,pos.y-TILE_SIZE));
	}
	main_sprite.setScale(sf::Vector2f(2.0,2.0));
	pacman_screen_layer.draw(main_sprite);
//	window->draw(shape);
//	window->display();
	
	//NETWORK DRAW
	/*
	if(direction==UP){
	//	Network::draw()
		main_sprite.setTexture(*textures_main[TILE_UP_1+int(switchting_variable)]);
	}
	else if(direction==LEFT){
		main_sprite.setTexture(*textures_main[TILE_LEFT_1+int(switchting_variable)]);
	}
	else if(direction==RIGHT){
		main_sprite.setTexture(*textures_main[TILE_RIGHT_1+int(switchting_variable)]);
	}
	else if(direction==DOWN){
		main_sprite.setTexture(*textures_main[TILE_DOWN_1+int(switchting_variable)]);	
	}
	else{
		sf::CircleShape shape(width/2);
		shape.setPosition(pos.x-TILE_SIZE,pos.y-TILE_SIZE);
		shape.setFillColor(sf::Color(100, 250, 50));
		pacman_screen_layer.draw(shape);	
	}
	main_sprite.setPosition(pos.x-TILE_SIZE,pos.y-TILE_SIZE);
	main_sprite.setScale(sf::Vector2f(2.0,2.0));
	pacman_screen_layer.draw(main_sprite);
//	window->draw(shape);
//	window->display();
*/
}
void Pacman::drawAllPacmans(){
	pacman_screen_layer.clear(sf::Color(0,0,0,0));
	for(int i=0;i<pacmans_length;i++){
		pacmans[i].draw();
//		pacmans[i].window->display();
	}
	pacman_screen_layer.display();
	pacman_screen_tile.setTexture(pacman_screen_layer.getTexture());
	pacmans[0].window->draw(pacman_screen_tile);
	
}
void  Pacman::drawOnTexture(){
	
}
void Pacman::moveAllPacmans(){
	for(int i=0;i<pacmans_length;i++){
		pacmans[i].reverseDirectionCheck();
		pacmans[i].move();
	}
}

void Pacman::respondToKeysAllPacmans(){
	for(int i=0;i<pacmans_length;i++){
		pacmans[i].respondToKeys();
	}
}
void Pacman::respondToKeys(){
	if(id==0){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			setFutureDirection(UP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
	 		setFutureDirection(LEFT);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
	    	setFutureDirection(DOWN);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
	    	setFutureDirection(RIGHT);
		}
	}
	else if(id==1){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::I)){
			setFutureDirection(UP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)){
	 		setFutureDirection(LEFT);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)){
	    	setFutureDirection(DOWN);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)){
	    	setFutureDirection(RIGHT);
		}
	}

	//else{setFutureDirection(NO);}
	//cout<<direction<<"\n";
}
Pacman::~Pacman(){
	cout<<"PACMAN KILLED "<<"\n";	
}
void Pacman::setupEverythingForPacman(){
	pacmans_length=0;
	pacmans=new Pacman[MAX_PACMANS];
	if (!pacmans){
   		cout << " pacmans: Memory allocation failed"<<"\n";
	}
	else{
		cout << "pacmans: Memory succesfully  allocated "<<"\n";
	}
//	textures_main=new sf::Texture*[MAX_PACMAN_TILES];
	textures_main=new int[MAX_PACMAN_TILES];
	textures_length=0;
	//textures_main.setLength(MAX_PACMAN_TILES,0);
	pacman_screen_tile.setPosition(sf::Vector2f(0.0,0.0));
	all_sprites=World::all_sprites;
//	sprites_pos.setLength(20);
}
void Pacman::destroyEverythingForPacman(){
	delete [] pacmans;
	delete [] textures_main;
}
void Pacman::addPacman(sf::RenderWindow *_window,World *_world){
	pacmans[pacmans_length].set(_window,_world);
	pacmans_length++;
}
void Pacman::checkCollision(){
	if(hitbox.getCollidedWithEatable()>-1){
		world->requestToPlaySound(EATING);
	}
	if(hitbox.getCollidedWithGhost()>-1){
		hitbox.doneWithGhost();
		die();
		
		//cout<<"collided With Ghost"<<"\n";
	}
	if(hitbox.getCollidedWithPacman()>-1){
		
	}
}
void Pacman::checkCollsionsForAllPacmans(){
	for(int i=0;i<pacmans_length;i++){
		pacmans[i].checkCollision();
	}
}
void Pacman::die(){
	world->requestToStopAllSounds();
	world->requestToPlaySound(MISS);
	cout<<"died"<<"\n";
	world->drawWorld();
	pacman_screen_layer.clear(sf::Color(0,0,0,0));
	int i=0;
	sf::Texture data;
	data.create(448,576);
	data.update(*window);
	sf::Sprite data_sprite;
	data_sprite.setTexture(data);
	main_sprite.setPosition(pos.x-TILE_SIZE,pos.y-TILE_SIZE);
	data_sprite.setPosition(0,0);
	for(i=0;i<11;i++){
		pacman_screen_layer.clear(sf::Color(0,0,0,0));
		pacman_screen_layer.draw(data_sprite);
		main_sprite.setTexture(all_sprites[textures_main[i+8]]);
		//main_sprite.setTexture(*textures_main[i+8]);
		main_sprite.setScale(sf::Vector2f(2.0,2.0));
		pacman_screen_layer.draw(main_sprite);
		pacman_screen_layer.display();
		pacman_screen_tile.setTexture(pacman_screen_layer.getTexture());
		pacmans[0].window->draw(pacman_screen_tile);
		window->display();
		Sleep(150);
	}
	resurect();
	justDied=true;			
}
void Pacman::resurect(){
	pos=Node::nodes[PACMAN_SPAWN_NODE].getPos();
	setCurrentNode(Node::nodes[PACMAN_SPAWN_NODE].giveMeYourAddress());
	setFutureNode(Node::nodes[37].giveMeYourAddress());
	direction=RIGHT;
	hitbox.doneWithPacman();
	hitbox.doneWithGhost();
}

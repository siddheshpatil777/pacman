#include "ghost.h"

Ghost *Ghost::ghosts;
int Ghost::ghosts_length;
sf::RenderTexture Ghost::ghost_screen_layer;
sf::Sprite Ghost::ghost_screen_tile; 
int *Ghost::textures_main;
sf::Texture* Ghost::all_sprites; 
int Ghost::textures_length;
Ghost::Ghost():Character(){
	nodeParents.setLength(70,NULL,NULL);
	paths.setLength(MAX_LENGTH_OF_PATHS);
	paths_future.setLength(MAX_LENGTH_OF_PATHS);
	paths_index=0;
	frequency=0;
	distance_to_end_future=0;
	distance_to_end_current=0;
}
Array<Node*> *Ghost::getPaths(){
	return &paths;
}
Array<Node*> *Ghost::getPathsFuture(){
	return &paths_future;
}
void Ghost::mainSetup(){
	
}
void Ghost::refreshPaths(){
	paths_index=0;
}
void Ghost::set(sf::RenderWindow *_window,World *_world){
	if(!ghost_screen_layer.create(448,576)){
		cout<<"Error while creating  Ghost texture "<<"\n";
	}
	else{
		cout<<"succesfully  creatied  Ghost screen texture "<<"\n";
	}
	setImportantVariables(_window,_world);
	cout<<"Ghost CREATED "<<"\n";	
	char t[20]={"G"};
	ghost_type=0;
	hitbox.setType(t);	
	id=ghosts_length;
	justMoved=true;
	pos=Node::getPos(5);
	setCurrentNode(Node::nodes[5].giveMeYourAddress());
	setFutureNode(Node::nodes[8].giveMeYourAddress());
	direction=RIGHT;
	forward=false;
	width=32;
	b=false;
}
void Ghost::draw(){
	ghost_screen_layer.clear(sf::Color(0,0,0,0));
	main_sprite.setPosition(pos.x-TILE_SIZE,pos.y-TILE_SIZE);
	if(direction==UP){
		//main_sprite.setTexture(*textures_main[0]);
		main_sprite.setTexture(all_sprites[textures_main[ghost_type*8+TILE_UP_1+int(switchting_variable)]]);
		Network::draw(textures_main[ghost_type*8+TILE_UP_1+int(switchting_variable)],sf::Vector2f(pos.x-TILE_SIZE,pos.y-TILE_SIZE));
	}
	else if(direction==LEFT){
	//	main_sprite.setTexture(*textures_main[0]);
		main_sprite.setTexture(all_sprites[textures_main[ghost_type*8+TILE_LEFT_1+int(switchting_variable)]]);
		Network::draw(textures_main[ghost_type*8+TILE_LEFT_1+int(switchting_variable)],sf::Vector2f(pos.x-TILE_SIZE,pos.y-TILE_SIZE));
	}
	else if(direction==DOWN){
	//	main_sprite.setTexture(*textures_main[0]);
		main_sprite.setTexture(all_sprites[textures_main[ghost_type*8+TILE_DOWN_1+int(switchting_variable)]]);
		Network::draw(textures_main[ghost_type*8+TILE_DOWN_1+int(switchting_variable)],sf::Vector2f(pos.x-TILE_SIZE,pos.y-TILE_SIZE));
	}
	else if(direction==RIGHT){
	//	main_sprite.setTexture(*textures_main[0]);
		main_sprite.setTexture(all_sprites[textures_main[ghost_type*8+TILE_RIGHT_1+int(switchting_variable)]]);
		Network::draw(textures_main[ghost_type*8+TILE_RIGHT_1+int(switchting_variable)],sf::Vector2f(pos.x-TILE_SIZE,pos.y-TILE_SIZE));
	}
	
	main_sprite.setScale(sf::Vector2f(2.0,2.0));
//	sf::RectangleShape shape(sf::Vector2f(32,32));
//	shape.setPosition(pos.x-width/2,pos.y-height/2);
//	shape.setFillColor(sf::Color(230, 3, 10));
	window->draw(main_sprite);
	//ghost_screen_layer.draw(main_sprite);
	
//	window->display();

}
void Ghost::drawOnTexture(){
	
}
void Ghost::moveAllGhosts(){
	for(int i=0;i<ghosts_length;i++){
	//	cout<<"Ghost moved "<<"\n";
		ghosts[i].move();
		ghosts[i].followPath();	
	}

}
void Ghost::drawAllGhosts(){
	
	ghost_screen_layer.clear(sf::Color(0,0,0,0));
	for(int i=0;i<ghosts_length;i++){
	//	cout<<"Ghost draw "<<"\n";	
		ghosts[i].draw();
//		ghosts[i].window->display();
	}
	ghost_screen_layer.display();
	ghost_screen_tile.setTexture(ghost_screen_layer.getTexture());
	ghosts[0].window->draw(ghost_screen_tile);
}
void Ghost::respondToKeysAllGhosts(){
		
	for(int i=0;i<ghosts_length;i++){
	//	cout<<"Ghost respond to key "<<"\n";
		ghosts[i].respondToKeys();
	}
}
void Ghost::respondToKeys(){
	if(id==0){
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
Ghost::~Ghost(){
	cout<<"Ghost KILLED "<<"\n";	
}
void Ghost::setupEverythingForGhost(){
	ghosts_length=0;
	ghosts=new Ghost[MAX_GHOSTS];
	textures_length=0;
	textures_main=new int[MAX_GHOST_TILES];
	for(int i=0;i<MAX_GHOST_TILES;i++){
		//textures_main=NULL;
	}
	all_sprites=World::all_sprites;
	ghost_screen_tile.setPosition(sf::Vector2f(0.0,0.0));
}
void Ghost::destroyEverythingForGhost(){
	delete [] ghosts;

	delete [] textures_main;
}
void Ghost::addGhost(int _ghost_type,sf::RenderWindow *_window,World *_world){
	ghosts[ghosts_length].set(_window,_world);
	ghosts[ghosts_length].ghost_type=_ghost_type;
	ghosts_length++;
}
void Ghost::loadAllSpritesFromFile(){
	//texture from 0 to 32 ghosst normal
	cout<<"started"<<"\n";
	for(int i=0;i<4;i++){
		for(int j=0;j<8;j++){
			textures_main[textures_length]=ghosts[0].world->responseToRequestForTile(sf::Vector2i(j,4+i));
			textures_length++;
		//	cout<<"textures_length++"<<"\n";
		}
	}
	//8888vvv88sss888888sponsponspon
	
	textures_main[textures_length++]=ghosts[0].world->responseToRequestForTile(sf::Vector2i(8,4));
	textures_main[textures_length++]=ghosts[0].world->responseToRequestForTile(sf::Vector2i(9,4));
	textures_main[textures_length++]=ghosts[0].world->responseToRequestForTile(sf::Vector2i(10,4));
	textures_main[textures_length++]=ghosts[0].world->responseToRequestForTile(sf::Vector2i(11,4));
	//
	textures_main[textures_length++]=ghosts[0].world->responseToRequestForTile(sf::Vector2i(8,5));
	textures_main[textures_length++]=ghosts[0].world->responseToRequestForTile(sf::Vector2i(9,5));
	textures_main[textures_length++]=ghosts[0].world->responseToRequestForTile(sf::Vector2i(10,5));
	textures_main[textures_length++]=ghosts[0].world->responseToRequestForTile(sf::Vector2i(11,5));
	
}
void Ghost::alligneToPath(){
	
}
void Ghost::findNewPath(){
	mainBehavior();
	paths.copyFrom(paths_future,NULL);
	distance_to_end_current=distance_to_end_future;
/*
	if(distance_to_end_future==distance_to_end_current){
		if(distance_to_end_current+paths[1]->getDistance(pos)>distance_to_end_future+paths_future[1]->getDistance(pos)){
			paths.copyFrom(paths_future,NULL);
			distance_to_end_current=distance_to_end_future;
		}
	}
	else{
		paths.copyFrom(paths_future,NULL);
		distance_to_end_current=distance_to_end_future;
	}
	*/

}
void Ghost::followPath(){
//	printPosition(pos);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
		paths_index=paths.index(current_node);
		current_node=Node::nodes[5].giveMeYourAddress();
		pos=current_node->getPos();
		direction=current_node->getDirectionOf(paths[paths_index+1]);
		future_node=Node::nodes[8].giveMeYourAddress();
		b=false;
	}
	/*
	cout<<"Ghost id = "<<ghost_type<<" {"<<"\n";
	if(current_node!=NULL){cout<<"current_node : "<<current_node->getId()<<"\n";}
	else{cout<<"current_node : "<<" NULL ";}cout<<"\n";	
	if(future_node!=NULL){cout<<"future_node : "<<future_node->getId()<<"\n";}
	else{cout<<"future_node : "<<" NULL ";}cout<<"\n";	
	*/
//	checkForFutureDirection();
	if(justMoved){
		justMoved=false;
	}
	findNewPath();
	//path calculated from currrent_node
	if(paths.contains(current_node)){
		paths_index=paths.index(current_node);	
		if(future_node!=paths[paths_index+1]){
			if(future_node!=NULL){
				//direction=future_node->getDirectionOf(current_node);
				//setFutureDirection(current_node->getDirectionOf(paths[paths_index+2]));
				findNewPath();
				paths_index=paths.index(current_node);
				setFutureDirection(current_node->getDirectionOf(paths[paths_index+1]));
			}
			else{
				findNewPath();
				paths_index=paths.index(current_node);
				direction=current_node->getDirectionOf(paths[paths_index+1]);
				future_node=paths[paths_index+1];
				move();
			//	cout<<"stuck"<<"\n";
			//	followPath();
			}	
		}
		else{
			paths_index=paths.index(current_node);
			if(paths.length()>=paths_index+2){
				direction=current_node->getDirectionOf(paths[paths_index+1]);
				setFutureDirection(paths[paths_index+1]->getDirectionOf(paths[paths_index+2]));
			}
			else{
				findNewPath();
				paths_index=paths.index(current_node);
				direction=current_node->getDirectionOf(paths[paths_index+1]);
				//direction=getFutureDirection();//current_node->getDirectionOf(paths[paths_index+1]);
			}
		}
	}
	else{
		findNewPath();
	}
	if(future_node==NULL){
		findNewPath();
		paths_index=paths.index(current_node);
		future_node=paths[paths_index+1];
		direction=current_node->getDirectionOf(future_node);
	//	cout<<"other nu ll statement"<<"\n";
		
	}
	//cout<<"distance_to_end_future = "<<distance_to_end_future<<"\n";
//	cout<<"distance_to_end_current"<<distance_to_end_current<<"\n";
//	for(int i=0;i<paths.length();i++){
//		if(paths[i]!=NULL){
//			cout<<paths[i]->getId()<<" , ";	
///		}
//	}
//	cout<<"\n";
//	cout<<"}"<<"\n";

}
void Ghost::setDistanceToEnd(int d){
	distance_to_end_future=d;//+future_node->getDistance(pos);
}
void Ghost::checkCollision(){
	if(hitbox.getCollidedWithPacman()){
		//stuff
		whenPacmanIsKilled();
		//
		hitbox.doneWithPacman();
	}
}
void Ghost::whenPacmanIsKilled(){
//	27 35
	pos=Node::getPos(GHOST_SPAWN_NODE);
	current_node=Node::nodes[GHOST_SPAWN_NODE].giveMeYourAddress();
	future_node=Node::nodes[35].giveMeYourAddress();
	direction=current_node->getDirectionOf(future_node);
	blinky();
	
}
void Ghost::checkCollisionForAllGhosts(){
	for(int i=0;i<ghosts_length;i++){
		ghosts[i].checkCollision();
	}
}
void Ghost::blinky(){
	Node *end=Pacman::pacmans[0].getFutureNode();
	if(end==NULL){
		end=Pacman::pacmans[0].getCurrentNode();
	}
//	Node *start=ghosts[BLINKY].getFutureNode();
//	if(start==NULL){
	Node *start=ghosts[BLINKY].getCurrentNode();
//	}
	ghosts[BLINKY].nodeParents.clear(NULL,NULL);
	int distance_to_end=0;
	Useful::DijkstraAlgorithm(ghosts[BLINKY].nodeParents,start,end,distance_to_end,ghosts[BLINKY].getDirection(),ghosts[BLINKY].getFutureDirection());
	ghosts[BLINKY].setDistanceToEnd(distance_to_end);
	ghosts[BLINKY].paths_future.clear(NULL);
	Node* t=end;
	while(1){
		ghosts[BLINKY].paths_future.push(t);
		if(t==NULL || t==start){
			break;
		}
		t=ghosts[BLINKY].nodeParents[t];	
	}
	ghosts[BLINKY].paths_future.reverse();
	cout<<"PATH => ";
	for(int i=0;i<ghosts[BLINKY].paths_future.length();i++){
		cout<<ghosts[BLINKY].paths_future[i]->getId()<<" ";
	}
	cout<<"\n";
	//ghosts[BLINKY].paths_future.print();
}
void Ghost::checkForFutureDirection(){
	char f=getFutureDirection();
	if((direction=='l' && f=='r')||(direction=='u' && f=='d')||(direction=='r' && f=='l')||(direction=='d' && f=='u')){
		future_node=current_node->getRandomNeighbourNodeButNotInOppositeDirection(direction);
		char d =current_node->getDirectionOf(future_node);	
		setFutureDirection(d);
		findNewPath();
	}
}
void Ghost::inky(){
}
void Ghost::pinky(){
	Node *end=Pacman::pacmans[0].getFutureNode();
	if(end!=NULL){
		end=end->doesNodeExistInThatDirection(Pacman::pacmans[0].getDirection());
		if(end==NULL){
			end=Pacman::pacmans[0].getFutureNode();
			if(end==NULL){
				end=Pacman::pacmans[0].getCurrentNode();
			}
		}
	}
	else{
		end=Pacman::pacmans[0].getCurrentNode();
	}
	Node *start=ghosts[PINKY].getCurrentNode();
	ghosts[PINKY].nodeParents.clear(NULL,NULL);
	//bool q=Node::doesThisPointExistWithPos(ghosts[BLINKY].getPosition());
	int distance_to_end=0;
	Useful::DijkstraAlgorithm(ghosts[PINKY].nodeParents,start,end,distance_to_end,ghosts[PINKY].getDirection(),ghosts[PINKY].getFutureDirection());
	ghosts[PINKY].setDistanceToEnd(distance_to_end);
	ghosts[PINKY].paths_future.clear(NULL);
	Node* t=end;
	while(1){
		ghosts[PINKY].paths_future.push(t);
		if(t==NULL || t==start){
			break;
		}
		t=ghosts[PINKY].nodeParents[t];	
	}
//	ghosts[BLINKY].paths_future.print();
	ghosts[PINKY].paths_future.reverse();
}
void Ghost::mainBehavior(){
	if(ghost_type==BLINKY){
		blinky();
	}
	if(ghost_type==PINKY){
		pinky();
	}
}
void Ghost::setupBlinky(){
	ghosts[BLINKY].ghost_type=BLINKY;
	ghosts[BLINKY].setMaxSpeed(200);
}
void Ghost::setupClyde(){
	
}
void Ghost::setupInky(){
	
}
void Ghost::setupPinky(){
	ghosts[PINKY].ghost_type=PINKY;
	ghosts[PINKY].setMaxSpeed(225);
}
void Ghost::setupAllGhosts(){
	setupBlinky();
	setupPinky();
	//setupClyde();
	//setupInky();
}
/*
void Ghost::followPath(){
//	printPosition(pos);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
		paths_index=paths.index(current_node);
		current_node=Node::nodes[5].giveMeYourAddress();
		pos=current_node->getPos();
		direction=current_node->getDirectionOf(paths[paths_index+1]);
		future_node=Node::nodes[8].giveMeYourAddress();
		b=false;
	}
	cout<<"Ghost id = "<<ghost_type<<" {"<<"\n";
	if(current_node!=NULL){cout<<"current_node : "<<current_node->getId()<<"\n";}
	else{cout<<"current_node : "<<" NULL ";}cout<<"\n";	
	if(future_node!=NULL){cout<<"future_node : "<<future_node->getId()<<"\n";}
	else{cout<<"future_node : "<<" NULL ";}cout<<"\n";	
	if(justMoved){
		justMoved=false;
		findNewPath();
	}
	//path calculated from currrent_node
	if(paths.contains(current_node)){
		paths_index=paths.index(current_node);
		if(future_node!=paths[paths_index+1]){
			if(future_node!=NULL){
				swap(current_node,future_node);
				direction=current_node->getDirectionOf(future_node);
				setFutureDirection(future_node->getDirectionOf(paths[paths_index+2]));
				findNewPath();
			}
			else{
				mainBehavior();
			}	
		}
		else{
			paths_index=paths.index(current_node);
			if(paths.length()>=paths_index+2){
				future_node=paths[paths_index+1];
				direction=current_node->getDirectionOf(paths[paths_index+1]);
				setFutureDirection(future_node->getDirectionOf(paths[paths_index+2]));
			}
			else if(paths.length()>=paths_index+1){
				direction=getFutureDirection();//current_node->getDirectionOf(paths[paths_index+1]);
			}
		}
	}
	else{
		findNewPath();
		followPath();
	}
	if(future_node==NULL){
		findNewPath();
		followPath();
		
		paths_index=paths.index(current_node);
		if(paths_index+1>=paths.length()){
			future_node=paths[paths_index+1];
			direction=current_node->getDirectionOf(paths[paths_index+1]);
			direction=current_node->getDirectionOf(paths[paths_index]);
		}
		else{
			paths_index=paths.index(current_node);
			current_node=future_node;
			future_node=paths[paths_index];
			direction=current_node->getDirectionOf(paths[paths_index]);
		}
		
	}
	cout<<"distance_to_end_future = "<<distance_to_end_future<<"\n";
	cout<<"distance_to_end_current"<<distance_to_end_current<<"\n";
//	if(forward==true && (distance_to_end_future<distance_to_end_current || distance_to_end_future!=distance_to_end_current)){
	//	
//	if(previous_node!=current_node){
//		paths.copyFrom(paths_future,NULL);
//		distance_to_end_current=distance_to_end_future;
//		forward=false;
//	}
	
	//
	for(int i=0;i<paths.length();i++){cout<<paths[i]->getId()<<" , ";}cout<<"\n";
	cout<<"}"<<"\n";

}
*/

#include "world.h"
sf::Texture *World::all_sprites;
int World::all_sprites_length;
World::World(int h,int w,int blockSize,sf::RenderWindow *_window){
	// IMPORTANT
	cout<<"WORLD CREATED "<<"\n";
	all_sprites_length=0;
	all_sprites= new sf::Texture[MAX_CHARACTER_TILES];
	int all_sprites_length;	
	// BASIC SETUP
	window=_window;
	height=h;
	width=w;
	world_scale=1.0;
	//
	Text::setupEveryThingForText("images/text/text_tile.png",window);
	Node::setupEverythingForPoint(36,28,16);
	Node::setCenterOffset(sf::Vector2f(8.0,8.0));
	///path
	Path::setupEverythingForPath(40);
	//	Maze
	Maze::setupEverythingForMaze(window,"images/main_tiles/");
	maze.set(height,width,36,28);
	maze.setMazeData("images/world/maze_template.png");
	maze.updateMaze();
//	maze.printMazeDataCode();
	
	// TEXTURE
	maze.findPoints();
	//Node::printAllPointData();
	Path::loadPathsFromFile("data/paths.txt");
	Node::assignNeighbors();
//	Network::registerBackground(maze.getPointerToMazeTexture());

//	Node::printAllNeighborsData();	
	setupForSound();
	loadSoundsFromFile();
}
void World::drawWorld(){
	maze.drawMaze();
//	sprite.setTexture(main_texture);
//	window->draw(sprite);
}
void World::displayPath(){
	Path::displayAllPaths(window);
}
void World::displayPoints(){
	//Node::displayAllPoints(window);
	Node::displayAllPointsWithNumbers(window);
}
bool World::isPathValid(sf::Vector2f a){
	bool temp=false;
	for(int i=0;i<Path::getPathsLength();i++){
		if(Path::paths[i].isItOnPath(a)){
			temp=true;
		}
	}
	return temp;
}
World::~World(){
	delete [] all_sprites;
	Path::destroyEverythingForPath();
	Node::destroyEverythingForPoint();
	Maze::destroyEverythingForMaze();
	Text::destroyEveryThingForText();
	destroyForSound();
	
	cout<<"WORLD DESTROYED"<<"\n";	
}
bool World::areTheseSameColors(sf::Color &left,sf::Color &right){
	if((left.r==right.r)&&(left.g==right.g)&&(left.b==right.b)){
		return true;
	}
	else{
		return false;
	}
}
sf::Texture* World::getPointerToAllSprites(){
	return all_sprites;
}
void World::loadAllSprites(char *_path){
	for(int i=0;i<MAX_CHARACTER_TILES;i++){
		all_sprites[i].create(TILE_SIZE,TILE_SIZE);
	}
	char path[50];
	strcpy(path,_path);
	sf::Image data;
	if(!data.loadFromFile(path)){
		cout<<"Error while loading  all_sprites textures "<<"\n";
	}
	else{
		cout<<"succesfully  loaded all_sprites textures "<<"\n";
	}
	data.createMaskFromColor(sf::Color::Black);
	for(int i=0;i<8;i++){
		for(int j=0;j<14;j++){
			all_sprites[all_sprites_length].loadFromImage(data,sf::IntRect(tileToRealCoords(j,i,TILE_SIZE),sf::Vector2i(TILE_SIZE,TILE_SIZE)));
//			Network::registerThisTexture(all_sprites[all_sprites_length]);
		//	sf::Sprite sprite;
		//	sprite.setPosition(sf::Vector2f(tileToRealCoords(j,i,TILE_SIZE).x,tileToRealCoords(j,i,TILE_SIZE).y));
		//	sprite.setTexture(all_sprites[all_sprites_length]);
		//	window->draw(sprite);
			all_sprites_length++;
		}
	}
	cout<<"all_sprites_length = "<<all_sprites_length<<"\n";
	//sprites_pos.
}
sf::Vector2i World::tileToRealCoords(int x,int y,int size){
	return sf::Vector2i(size*x,size*y);
}

int World::responseToRequestForTile(sf::Vector2i _tile_pos){

	int a=_tile_pos.y*14+_tile_pos.x;
	return a;		
	//return &all_sprites[a];
}
void World::setupForSound(){
	all_sounds_length=0;
	all_sounds=new sf::Sound[MAX_SOUNDS];
	all_sound_buffers=new sf::SoundBuffer[MAX_SOUNDS];
//	all_sound_buffers=new sf::Music[MAX_SOUNDS];
	
}
void World::destroyForSound(){
	delete [] all_sounds;
	delete [] all_sound_buffers;
}
void World::loadSoundsFromFile(){
	char main_path[40]={"sounds"};char path[40];
	
	strcpy(path,main_path);strcat(path,"/coffee-break-music.wav");all_sound_buffers[COFFEE_BREAK_MUSIC].loadFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/credit.wav");all_sound_buffers[CREDIT].loadFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/eating.wav");all_sound_buffers[EATING].loadFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/eating-fruit.wav");all_sound_buffers[EATING_FRUIT].loadFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/eating-ghost.wav");all_sound_buffers[EATING_GHOST].loadFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/extend.wav");all_sound_buffers[EXTEND].loadFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/ghost-normal-move.wav");all_sound_buffers[GHOST_NORMAL_MOVE].loadFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/ghost-return-to-home.wav");all_sound_buffers[GHOST_RETURN_TO_HOME].loadFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/ghost-spurt-move-1.wav");all_sound_buffers[GHOST_SPURT_MOVE_1].loadFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/ghost-spurt-move-2.wav");all_sound_buffers[GHOST_SPURT_MOVE_2].loadFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/ghost-spurt-move-3.wav");all_sound_buffers[GHOST_SPURT_MOVE_3].loadFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/ghost-spurt-move-4.wav");all_sound_buffers[GHOST_SPURT_MOVE_4].loadFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/ghost-turn-to-blue.wav");all_sound_buffers[GHOST_TURN_TO_BLUE].loadFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/miss.wav");all_sound_buffers[MISS].loadFromFile(path);all_sounds_length++;
	//
	strcpy(path,main_path);strcat(path,"/start-music.wav");
	if(!all_sound_buffers[START_MUSIC].loadFromFile(path)){
		cout<<"error while loading sound"<<"\n";
	}
	
	/*
	strcpy(path,main_path);strcat(path,"/coffee-break-music.wav");all_sound_buffers[COFFEE_BREAK_MUSIC].openFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/credit.wav");all_sound_buffers[CREDIT].openFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/eating.wav");all_sound_buffers[EATING].openFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/eating-fruit.wav");all_sound_buffers[EATING_FRUIT].openFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/eating-ghost.wav");all_sound_buffers[EATING_GHOST].openFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/extend.wav");all_sound_buffers[EXTEND].openFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/ghost-normal-move.wav");all_sound_buffers[GHOST_NORMAL_MOVE].openFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/ghost-return-to-home.wav");all_sound_buffers[GHOST_RETURN_TO_HOME].openFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/ghost-spurt-move-1.wav");all_sound_buffers[GHOST_SPURT_MOVE_1].openFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/ghost-spurt-move-2.wav");all_sound_buffers[GHOST_SPURT_MOVE_2].openFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/ghost-spurt-move-3.wav");all_sound_buffers[GHOST_SPURT_MOVE_3].openFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/ghost-spurt-move-4.wav");all_sound_buffers[GHOST_SPURT_MOVE_4].openFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/ghost-turn-to-blue.wav");all_sound_buffers[GHOST_TURN_TO_BLUE].openFromFile(path);all_sounds_length++;
	strcpy(path,main_path);strcat(path,"/miss.wav");all_sound_buffers[MISS].openFromFile(path);all_sounds_length++;
	//
	strcpy(path,main_path);strcat(path,"/start-music.wav");
	if(!all_sound_buffers[START_MUSIC].openFromFile(path)){
		cout<<"error while loading sound"<<"\n";
	}
	all_sounds_length++;
	*/
	for(int i=0;i<MAX_SOUNDS;i++){
		all_sounds[i].setBuffer(all_sound_buffers[i]);
	}
	
}
void World::requestToPlaySound(int id){
	if(0==all_sounds[id].getStatus()){
		all_sounds[id].play();
	}
	
//	all_sound_buffers[id].play();
}
void World::requestToStopAllSounds(){
	for(int i=0;i<MAX_SOUNDS;i++){
		all_sounds[i].stop();
	}
}

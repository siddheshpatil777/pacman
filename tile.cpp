#include "tile.h"
Tile *Tile::tiles;
int Tile::tiles_length;
char Tile::parent_path[30];
sf::RenderWindow *Tile::window;
sf::RenderTexture *Tile::offscreen_window;
Tile::Tile(){
	color=sf::Color::Black;
	strcpy(name,"nothing");
	//image_data.loadFromFile("noPath");
	if(!texture_data.create(16,16)){
		cout<<"ERRROR while creating TILE texture"<<"\n";
	}
	code=-1;
}

Tile::~Tile(){
}
void Tile::set(sf::Color _color,char _path[],char _name[],int _code){
	color=_color;
	strcpy(name,_name);
	//sf::IntRect area(0,0,16,16);
	if(!image_data.loadFromFile(_path)){
		cout<<"could not load "<<_path<<" "<<"\n";
	}
	else{
		cout<<"TILE texture loaded  "<<_path<<"  SUCCESFULLY "<<"\n";
	}
	/*
	if(!){
		cout<<"could not load update texture from image"<<"\n";
	}
	else{
		cout<<"TILE texture updated from image SUCCESFULLY "<<"\n";
	}
	*/
	texture_data.update(image_data);
	sprite.setTexture(texture_data);
	code=_code;
}
void Tile::addTile(sf::Color _color,char _name[]){
	char path[50]={""};
	strcpy(path,parent_path);
//	strcat(path,"/");
	strcat(path,_name);
	strcat(path,".png");
	tiles[tiles_length].set(_color,path,_name,tiles_length);
	//if(!tiles[tiles_length].texture_data.create(16,16)){cout<<"ERRROR while creating TILE texture"<<"\n";}
	tiles_length++;
}
void Tile::setupEveryThingForTile(sf::RenderWindow *_window,sf::RenderTexture *_offscreen_window,char p[]){
	cout<<"EVERY THING SET UP FOR TILES"<<"\n";
	offscreen_window=_offscreen_window;
	window=_window;
	setParentPath(p);
	
	tiles_length=0;
	tiles=new Tile[MAX_TILES];
}
void Tile::destroyEveryThingForTile(){
	cout<<"EVERY THING DESTROYED FOR TILES"<<"\n";
	delete [] tiles;
}
int Tile::getTileCodeByColor(sf::Color c){
	for(int i=0;i<tiles_length;i++){
		if(Tile::tiles[i].color==c){
			return Tile::tiles[i].code;
		}
	}
}
void Tile::drawAt(sf::Vector2f pos,int tile_code){
	tiles[tile_code].sprite.setPosition(pos);
	offscreen_window->draw(tiles[tile_code].sprite);
	offscreen_window->display();
}
void Tile::setParentPath(char p[]){
	strcpy(parent_path,p);
}
void Tile::setTexture(){
	sprite.setTexture(texture_data);
}
sf::Texture Tile::getTextureByCode(int c){
	return tiles[c].texture_data;
}


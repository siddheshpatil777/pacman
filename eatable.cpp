#include "eatable.h"
sf::RenderTexture Eatable::eatable_screen_layer;
sf::Sprite Eatable::eatable_screen_tile; 
sf::RenderWindow *Eatable::window;
World *Eatable::world;
Eatable *Eatable::eatables;
//
sf::Texture Eatable::pop_texture;
sf::Texture Eatable::booster_texture;
sf::Texture Eatable::fruit_texture;
sf::Texture Eatable::blank_texture;
//
sf::Sprite Eatable::pop_sprite;
sf::Sprite Eatable::booster_sprite;
sf::Sprite Eatable::fruit_sprite;
sf::Sprite Eatable::blank;
//
int Eatable::eatables_length;
int Eatable::tile_size;
sf::Vector2i Eatable::offset;
Eatable::Eatable(){
	tileDeleted=false;
	ate=false;
	width=height=6;
	type=-1;
}

Eatable::~Eatable(){
}
void Eatable::setPosition(sf::Vector2f _pos){
	pos=_pos;
}
void Eatable::setPosition(sf::Vector2i _tile_pos){
	tile_pos=_tile_pos;
}
void Eatable::setImportantVariables(sf::RenderWindow *_window,World *_world){
	window=_window;
	world=_world;
}
void Eatable::checkCollision(){
	if(ate==false){
		if(hitbox.getCollidedWithPacman()>-1){
			update();
			ate=true;
			//cout<<"ate became true"<<"\n";
		}
	}
	
}
void Eatable::checkCollsionsForAllEatables(){
	for(int i=0;i<eatables_length;i++){
		eatables[i].checkCollision();
	}
}
void Eatable::setupAllEatables(){
	//eatable_screen_layer.clear(sf::Color(0,0,0,0));
	eatable_screen_layer.clear(sf::Color(0,0,0,0));
	for(int i=0;i<eatables_length;i++){
		eatables[i].draw();
	//	window->display();
	//	eatable_screen_layer.display();
	}
	eatable_screen_tile.setTexture(eatable_screen_layer.getTexture());
}
void Eatable::update(){
	if(ate==true ){
		tileDeleted=true;
		blank.setPosition(sf::Vector2f(pos.x-offset.x,pos.y-offset.y));
		eatable_screen_layer.draw(blank);
	}
}
void Eatable::updateAllEatables(){
	for(int i=0;i<eatables_length;i++){
		eatables[i].update();
	}
	eatable_screen_layer.display();
	eatable_screen_tile.setTexture(eatable_screen_layer.getTexture());
}
void Eatable::drawAllEatables(){
//	eatable_screen_tile.setScale(1.0f,-1.0f);
//	eatable_screen_tile.setPosition(0.0f,576.0f);
	window->draw(eatable_screen_tile);
	//window->display();
}
void Eatable::setupEverythingForEatable(sf::RenderWindow *_window,World *_world){
	setImportantVariables(_window,_world);
	cout<<"Evertything setup for Eatables"<<"\n";
	eatables_length=0;
	offset=sf::Vector2i(8,8);
	tile_size=16;
	eatables=new Eatable[MAX_EATABLES];
	if (!eatables){
   		cout << "eatables : Memory allocation failed"<<"\n";
	}
	else{
		cout << "eatables : Memory succesfully  allocated  "<<"\n";
	}
	if(!eatable_screen_layer.create(448,576)){
		cout<<"failed to create eatables texture"<<"\n";
	}
	else{
		cout<<"succesfully created eatables texture"<<"\n";
	}
	//eatable_screen_layer.clear(sf::Color(0,0,0,0));
}
void Eatable::set(sf::Vector2i _tile_pos,char *_type){
	tile_pos=_tile_pos;
	pos.x=tile_size*tile_pos.x+offset.x;
	pos.y=tile_size*tile_pos.y+offset.y;
	hitbox.set(&pos,2,2,sf::Vector2i(4,4),2);
	hitbox.setType("EATABLE");
	if(strcmp(_type,"P")==0||strcmp(_type,"p")==0||strcmp(_type,"POP")==0){
		type=POP;
	}
	else if(strcmp(_type,"f")==0||strcmp(_type,"F")==0||strcmp(_type,"FRUIT")==0){
		type=FRUIT;
	}
	else if(strcmp(_type,"b")==0||strcmp(_type,"B")==0||strcmp(_type,"BOOSTER")==0){
		type=BOOSTER;
	}
	else{
		type=NONE_OF_THE_ABOVE;
	}
}
void Eatable::destroyEverythingForEatable(){
	delete [] eatables;
	cout<<"Evertything destroyed for Eatables"<<"\n";
}

void Eatable::addEatable(sf::Vector2i _tile_pos,char *_type){
	eatables[eatables_length].set(_tile_pos,_type);
	eatables_length++;
}
void Eatable::draw(){
	
		if(type==POP){
			pop_sprite.setPosition(sf::Vector2f(pos.x-offset.x,pos.y-offset.y));
			eatable_screen_layer.draw(pop_sprite);
		//	window->draw(pop_sprite);
			//eatable_screen_layer.display();
		}
		else if(type==FRUIT){
			fruit_sprite.setPosition(sf::Vector2f(pos.x-offset.x,pos.y-offset.y));
			eatable_screen_layer.draw(fruit_sprite);
	//	window->draw(pop_sprite);
			//eatable_screen_layer.display();
		}
		else if(type==BOOSTER){
			booster_sprite.setPosition(sf::Vector2f(pos.x-offset.x,pos.y-offset.y));
			eatable_screen_layer.draw(booster_sprite);
	//	window->draw(pop_sprite);
		//	eatable_screen_layer.display();
		}
	
}
void Eatable::getEated(){
	ate=false;
}
void Eatable::die(){
}
void Eatable::drawOnTexture(){
	
}
void Eatable::loadAllEatablesFromFile(char* path){
	char p[30];
	strcpy(p,path);
	strcat(p,"pop_tile.png");
	if(!pop_texture.loadFromFile(p)){
		cout<<"failed to load eatables from file"<<"\n";
	}
	else{
		cout<<"succesfully loaded eatables from file"<<"\n";
	}
	pop_sprite.setTexture(pop_texture);
	strcpy(p,path);
	strcat(p,"booster_tile.png");
	if(!booster_texture.loadFromFile(p)){
		cout<<"failed to load eatables from file"<<"\n";
	}
	else{
		cout<<"succesfully loaded eatables from file"<<"\n";
	}
	booster_sprite.setTexture(booster_texture);
	//
	strcpy(p,path);
	strcat(p,"blank_tile.png");
	if(!blank_texture.loadFromFile(p)){
		cout<<"failed to load eatables from file"<<"\n";
	}
	else{
		cout<<"succesfully loaded eatables from file"<<"\n";
	}
	blank.setTexture(blank_texture);
}
void Eatable::loadAllEatables(char* path){
	sf::Image tempImage;
	if(!tempImage.loadFromFile(path)){
		cout<<"failed to load eatables from tempplate"<<"\n";
	}
	else{
		cout<<"succesfully loaded eatables from tempplate"<<"\n";
	}
	sf::Color color_booster(255,255,255);
	sf::Color color_pop(96,96,96);
	sf::Color temp;
	for(int i=0;i<tempImage.getSize().y;i++){
		for(int j=0;j<tempImage.getSize().x;j++){
			temp=tempImage.getPixel(j,i);
			if(areTheseSameColors(color_pop,temp)){
				addEatable(sf::Vector2i(j,i),"POP");
			//	cout<<"POP added to eatables"<<"\n";
			}
			else if(areTheseSameColors(color_booster,temp)){
				addEatable(sf::Vector2i(j,i),"BOOSTER");
			//	cout<<"BOOSTER added to eatables"<<"\n";
			}
		}
	}
	cout<<"eatables_length ="<<eatables_length<<"\n";
}
bool Eatable::areTheseSameColors(sf::Color &left,sf::Color &right){
	if((left.r==right.r)&&(left.g==right.g)&&(left.b==right.b)){
		return true;
	}
	else{
		return false;
	}
}

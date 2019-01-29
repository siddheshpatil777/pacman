#include "hitbox.h"
int Hitbox::eatables_length;
int Hitbox::pacmans_length;
int Hitbox::ghosts_length;
int Hitbox::max_hitboxes;
Hitbox **Hitbox::hitboxes_of_pacmans;
Hitbox **Hitbox::hitboxes_of_eatables;
Hitbox **Hitbox::hitboxes_of_ghosts;
sf::RenderWindow *Hitbox::window;
//
sf::RenderTexture Hitbox::hitbox_screen_texture;
sf::Sprite Hitbox::hitbox_screen_sprite;
void Hitbox::set(sf::Vector2f *_pos,int h,int w,sf::Vector2i _offset,int _type){
	type='n';
	hitbox_screen_texture.create(448,576);
	//setType(t);
	offset=_offset;
	pos=_pos;
	TYPE=-1;
	height=h;
	width=w;
	color.r=255;
	color.g=0;
	color.b=0;
	color.a=255;
	alive=true;
	
//	size=sf::Vector2f(width,height);
	
	if(_type==0 || _type==1){
		size=sf::Vector2f(8,8);
		box.setSize(size);
		box.setOutlineColor(color);
		box.setFillColor(sf::Color(0,0,0,0));
		box.setOutlineThickness(3);
		hitbox=sf::FloatRect(sf::Vector2f(pos->x-TILE_SIZE+12,pos->y-TILE_SIZE+12),size);
	}
	else{
		size=sf::Vector2f(2,2);
		box.setSize(size);
		box.setOutlineColor(color);
		box.setFillColor(sf::Color(0,0,0,0));
		box.setOutlineThickness(3);
		sf::Vector2f temp(pos->x-1,pos->y-1);
		hitbox=sf::FloatRect(temp,size);
	}
	
	
}
Hitbox::Hitbox(){
	collided_with_eatable=-1;
	collided_with_ghost=-1;
	collided_with_pacman=-1;
	alive=false;
}
void Hitbox::drawHitbox(){
	//cout<<this->hitbox.leftx<<this->hitbox.left.y;
	if(TYPE==1 ||TYPE==0){
		/*
		cout<<"hitbox.left = "<<hitbox.left<<"\n";
		cout<<"hitbox.top = "<<hitbox.top<<"\n";
		cout<<"hitbox.width = "<<hitbox.width<<"\n";
		cout<<"hitbox.height = "<<hitbox.height<<"\n";
		*/
		box.setPosition(sf::Vector2f(hitbox.left,hitbox.top));
	}
	else{
		box.setPosition(sf::Vector2f(hitbox.left,hitbox.top));
	}
	hitbox_screen_texture.draw(box);
	//window->draw(box);
}
Hitbox::~Hitbox(){
	
}
//Hitbox::setRenderWindow(sf::RenderWindow *_window){	}
Hitbox *Hitbox::giveMeYourAddress(){
	return this;
}
void Hitbox::registeringAddress(){
	//hitboxes[hitboxes_length++]=&giveMeYourAddress();
}
void Hitbox::setupEverythingForHitboxes(sf::RenderWindow *_window,int _max_hitboxes=10){
	//window=(sf::RenderWindow*)0;
	window=_window;
	max_hitboxes=_max_hitboxes;
	pacmans_length=0;
	eatables_length=0;
	ghosts_length=0;
	hitboxes_of_pacmans=new Hitbox*[MAX_PACMAN_HITBOXES];
	if (!hitboxes_of_pacmans){
   		cout << " hitboxes_of_pacmans: Memory allocation failed"<<"\n";
	}
	else{
		cout << "hitboxes_of_pacmans: Memory succesfully  allocated  "<<"\n";
	}
	hitboxes_of_eatables=new Hitbox*[MAX_EATABLE_HITBOXES];
	if (!hitboxes_of_eatables){
   		cout << " hitboxes_of_eatables: Memory allocation failed"<<"\n";
	}
	else{
		cout << "hitboxes_of_eatables: Memory succesfully  allocated "<<"\n";
	}
	hitboxes_of_ghosts=new Hitbox*[MAX_GHOST_HITBOXES];
	if (!hitboxes_of_ghosts){
   		cout << " hitboxes_of_ghosts: Memory allocation failed"<<"\n";
	}
	else{
		cout << "hitboxes_of_ghosts: Memory succesfully  allocated "<<"\n";
	}
	
	for(int i=0;i<MAX_PACMAN_HITBOXES;i++){
		hitboxes_of_pacmans[i]=NULL;
	}
	for(int i=0;i<MAX_EATABLE_HITBOXES;i++){
		hitboxes_of_eatables[i]=NULL;
	}
	for(int i=0;i<MAX_GHOST_HITBOXES;i++){
		hitboxes_of_ghosts[i]=NULL;
	}
}
void Hitbox::destroyEverythingForHitboxes(){
	//max_hitboxes=10;
	delete [] hitboxes_of_pacmans;
	delete [] hitboxes_of_eatables;
	delete [] hitboxes_of_ghosts;
}
void Hitbox::printAllHitboxData(){
	cout<<"HITBOX DATA"<<"\n";
	cout<<"pacmans_length "<<pacmans_length<<"\n";
	cout<<"ghosts_length "<<ghosts_length<<"\n";
	cout<<"eatables_length "<<eatables_length<<"\n";
}
void Hitbox::drawAllHitboxes(){
	hitbox_screen_texture.clear(sf::Color(0,0,0,0));
	for(int i=0;i<pacmans_length;i++){
		hitboxes_of_pacmans[i]->drawHitbox();
	}
	for(int i=0;i<ghosts_length;i++){
		hitboxes_of_ghosts[i]->drawHitbox();
	}
	
	for(int i=0;i<eatables_length;i++){
		hitboxes_of_eatables[i]->drawHitbox();
	}
	hitbox_screen_texture.display();
	hitbox_screen_sprite.setTexture(hitbox_screen_texture.getTexture());
	window->draw(hitbox_screen_sprite);
	window->display();
}
void Hitbox::refresh(){
	if(TYPE==1 || TYPE==0){
		hitbox=sf::FloatRect(sf::Vector2f(pos->x-TILE_SIZE+13,pos->y-TILE_SIZE+12),size);
//		cout<<"hitbox.left = "<<hitbox.left<<"\n";
//		cout<<"hitbox.top = "<<hitbox.top<<"\n";
//		cout<<"hitbox.width = "<<hitbox.width<<"\n";
//		cout<<"hitbox.height = "<<hitbox.height<<"\n";
	}
	else{
		//hitbox=sf::FloatRect(*pos,size);
			hitbox=sf::FloatRect(sf::Vector2f(pos->x-1,pos->y-1),size);
			/*
		cout<<"hitbox.left = "<<hitbox.left<<"\n";
		cout<<"hitbox.top = "<<hitbox.top<<"\n";
		cout<<"hitbox.width = "<<hitbox.width<<"\n";
		cout<<"hitbox.height = "<<hitbox.height<<"\n";
		*/
	}
//	hitbox=sf::FloatRect(*pos,size);
}
void Hitbox::HandleHitboxes(){
//	sf::Mutex mutex;
	//pacman with ghost
	
	for(int i=0;i<pacmans_length;i++){
		for(int j=0;j<ghosts_length;j++){
		//	mutex.lock();
			if(hitboxes_of_pacmans[i]->alive && hitboxes_of_ghosts[j]->alive){
				hitboxes_of_pacmans[i]->refresh();
				hitboxes_of_ghosts[j]->refresh();
				bool hit=hitboxes_of_pacmans[i]->hitbox.intersects(hitboxes_of_ghosts[j]->hitbox);
			
				if(hit){
					hitboxes_of_pacmans[i]->collided_with_ghost=j;
					//cout<<"pacman hit ghost"<<"\n";
				}
			}
			//mutex.unlock();
		}
	}
	for(int i=0;i<pacmans_length;i++){
		for(int j=0;j<eatables_length;j++){
		//	mutex.lock();
			if(hitboxes_of_pacmans[i]->alive && hitboxes_of_eatables[j]->alive){
				hitboxes_of_pacmans[i]->refresh();
				hitboxes_of_eatables[j]->refresh();
				bool hit=hitboxes_of_pacmans[i]->hitbox.intersects(hitboxes_of_eatables[j]->hitbox);
			//	mutex.unlock();
				if(hit){
					hitboxes_of_pacmans[i]->collided_with_eatable=j;
					hitboxes_of_eatables[j]->collided_with_pacman=i;
				}
			}
		}
	}
	
	//pacman with eatable
//	for(int i=0;i<eatables_length;i++){}
}
void Hitbox::setType(char t[]){
	if(strcmp(t,"pacman")==0||strcmp(t,"PACMAN")==0||strcmp(t,"p")==0||strcmp(t,"P")==0){
		type=PACMAN;
		hitboxes_of_pacmans[pacmans_length]=giveMeYourAddress();
		hitboxes_of_pacmans[pacmans_length]->TYPE=0;
		pacmans_length++;
		box.setOutlineColor(sf::Color(255,0,0));
	//	cout<<" pacman added to settype"<<"\n";
	}
	if(strcmp(t,"ghost")==0||strcmp(t,"GHOST")==0||strcmp(t,"g")==0||strcmp(t,"G")==0){
		type=GHOST;
		hitboxes_of_ghosts[ghosts_length]=giveMeYourAddress();
		hitboxes_of_ghosts[ghosts_length]->TYPE=1;
		ghosts_length++;
		box.setOutlineColor(sf::Color(0,255,0));
	//	cout<<" GHOST added to settype"<<"\n";
	}
	
	if(strcmp(t,"eatable")==0||strcmp(t,"EATABLE")==0||strcmp(t,"e")==0||strcmp(t,"E")==0){
		type=EATABLE;
		hitboxes_of_eatables[eatables_length]=giveMeYourAddress();
		hitboxes_of_eatables[eatables_length]->TYPE=2;
	//	cout<<" EATABLES added to settype"<<"\n";
	box.setOutlineColor(sf::Color(0,0,255));
		eatables_length++;
	}
}
void Hitbox::setOwnerID(int id){
	owner_id=id;
}
//Hitbox::setupEverythingForHitboxes();
int Hitbox::getCollidedWithEatable(){
	return collided_with_eatable;
}
int Hitbox::getCollidedWithGhost(){
	return collided_with_ghost;
}
int Hitbox::getCollidedWithPacman(){
	return collided_with_pacman;
}
void Hitbox::doneWithEatable(){
	collided_with_eatable=-1;
}
void Hitbox::doneWithGhost(){
	collided_with_ghost=-1;
}
void Hitbox::doneWithPacman(){
	collided_with_pacman=-1;
}

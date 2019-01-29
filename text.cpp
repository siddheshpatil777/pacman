#include "text.h"
int Text::images_length;
//char* Text::path;
int Text::text_tile_size;

sf::Texture *Text::images;
sf::RenderWindow *Text::window;
sf::Texture Text::main_texture_tile;
sf::Image Text::main_data;
sf::Sprite Text::text_sprite;
sf::RenderTexture Text::text_screen_tile;
sf::Sprite Text::text_screen_sprite;
void Text::setupEveryThingForText(char *_path,sf::RenderWindow *_window){
//	strcpy(path,_path);
	text_screen_tile.create(DISPLAY_WIDTH,DISPLAY_HEIGHT);
	text_screen_sprite.setPosition(sf::Vector2f(0.0,0.0));
	images_length=0;
	window=_window;
	text_tile_size=0;
	images=new sf::Texture[MAX_IMAGES];
	if(!main_data.loadFromFile(_path)){
		cout<<"failed to load text image data"<<"\n";
	}
	else{
		cout<<"succesfully loaded text image data"<<"\n";
	}
	main_data.createMaskFromColor(sf::Color::Black);
	for(int i=0;i<MAX_IMAGES;i++){
		images[i].create(SMALL_TILE_SIZE,SMALL_TILE_SIZE);
	}
	splitData();
	
}
void Text::splitData(){
//	for(int row=0;row<21;row+=4){
	int row=0;
	//for(row=0;row<27;row+=4){
		for(int i=0;i<24;i++){
			for(int j=0;j<15;j++){
				if((i+1)%4!=0){
					if((j==12||j==13||j==14) && (i==1||i==5||i==9||i==13||i==17||i==21)){
						images[images_length].loadFromImage(main_data,sf::IntRect(j*SMALL_TILE_SIZE,(i)*SMALL_TILE_SIZE,3*SMALL_TILE_SIZE,SMALL_TILE_SIZE));
						images_length++;
						continue;
					}
					else{
						images[images_length].loadFromImage(main_data,sf::IntRect(j*SMALL_TILE_SIZE,(i)*SMALL_TILE_SIZE,SMALL_TILE_SIZE,SMALL_TILE_SIZE));
						//cout<<
						images_length++;
					}
				}
			}
		}
//	}	
	//}
}
void Text::testAllCharacters(){
	window->clear(sf::Color(0,0,0,0));
	sf::RenderTexture tempTexture;
	tempTexture.create(200,240);
	int length=0;
	sf::Sprite sprite;
	for(int i=0;i<24;i++){
		for(int j=0;j<15;j++){
			if(length<images_length){
				sprite.setPosition(sf::Vector2f(j*SMALL_TILE_SIZE,i*SMALL_TILE_SIZE));
				sprite.setTexture(images[length]);
				tempTexture.draw(sprite);
				length++;
			}
		}
	}
	sf::Texture te=tempTexture.getTexture();
	sf::Sprite sp;
	sp.setTexture(te);
	sp.setScale(sf::Vector2f(1.0,-1.0));
	sp.setPosition(sf::Vector2f(200,240));
	window->draw(sp);
	window->display();
//	texture
	sf::Image saveData=te.copyToImage();
	if(!saveData.saveToFile("images/teeeefsfeeeeest.png")){
		cout<<"could not save "<<"\n";
	}
	
}
void Text::destroyEveryThingForText(){
	delete [] images;
}
void Text::drawTextToSprite(){
	text_screen_tile.clear(sf::Color(0,0,0,0));
	char main_text[50];
	strcpy(main_text,this->data);
	int q;
	for(int j=0;j<strlen(main_text);j++){
		q=main_text[j];
		if(q==32){
			text_sprite.setTexture(images[44]);
		}
		else if(isalpha(main_text[j])){
			if(q>=97 && q<97+26){	
				text_sprite.setTexture(images[(color*45)+q-97]);
			}		
		}
		else{
			text_sprite.setTexture(images[(color*45)+(30+q-48)]);
		}
		sf::Vector2f _pos((j+pos.x)*TILE_SIZE,(pos.y)*TILE_SIZE);
		text_sprite.setPosition(_pos);
		text_sprite.setScale(sf::Vector2f(2.0,2.0));
		text_screen_tile.draw(text_sprite);		
	}
	text_screen_tile.display();
	this->t=sf::Texture(text_screen_tile.getTexture());
	this->sprite.setTexture(this->t);
//	sprite.setTexture(text_screen_tile.getTexture());
//	window->draw(text_screen_sprite);
}
//void Text::drawText(char *text,sf::Vector2i tile,int color){
//	text_screen_tile.clear(sf::Color(0,0,0,0));
//	char main_text[50];
//	strcpy(main_text,text);
//	int q;
//	for(int j=0;j<strlen(main_text);j++){
//		q=main_text[j];
//		if(q==32){
//			text_sprite.setTexture(images[44]);
//		}
//		else if(isalpha(main_text[j])){
//			if(q>=97 && q<97+26){	
//				text_sprite.setTexture(images[(color*45)+q-97]);
//			}		
//		}
//		else{
//			text_sprite.setTexture(images[(color*45)+(30+q-48)]);
//		}
//		sf::Vector2f _pos((j+tile.x)*TILE_SIZE,(tile.y)*TILE_SIZE);
//		text_sprite.setPosition(_pos);
//		text_sprite.setScale(sf::Vector2f(2.0,2.0));
//		text_screen_tile.draw(text_sprite);		
//	}
//	text_screen_tile.display();
//	text_screen_sprite.setTexture(text_screen_tile.getTexture());
//	window->draw(text_screen_sprite);
//}

Text::Text(char data[] ,int color,sf::Vector2i pos){
	strcpy(this->data,data);
	this->color=color;
	this->pos=pos;
//	sprite.setPosition(this->pos.x*TILE_SIZE,this->pos.y*TILE_SIZE);
	this->drawTextToSprite();
}
void Text::draw(){
	window->draw(this->sprite);
//	screen_data.draw(text_sprite);	
}
Text::Text(){
	
}
void Text::set(char data[] ,int color,sf::Vector2i pos){
	strcpy(this->data,data);
	this->color=color;
	this->pos=pos;
//	sprite.setPosition(this->pos.x*TILE_SIZE,this->pos.y*TILE_SIZE);
	this->drawTextToSprite();
}
void Text::setColor(int color){
	
}
void Text::setPosition(sf::Vector2i pos){
	
}

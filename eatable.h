#ifndef EATABLE_H
#define EATABLE_H
#include <iostream>
#include <string.h>
#include "world.h"
#include "hitbox.h"
using namespace std;
#include "SFML/Graphics.hpp"
#define MAX_EATABLES 250
#define POP 0
#define FRUIT 1
#define BOOSTER 2
#define NONE_OF_THE_ABOVE -1
class Eatable{
	private:
		//
		static sf::Texture pop_texture;
		static sf::Texture booster_texture;
		static sf::Texture fruit_texture;
		static sf::Texture blank_texture;
		//
		static sf::Sprite pop_sprite;
		static sf::Sprite booster_sprite;
		static sf::Sprite fruit_sprite;
		static sf::Sprite blank;
		//
		//
		static sf::Sprite eatable_screen_tile; 
		static	sf::RenderWindow *window;
		static sf::RenderTexture eatable_screen_layer;
		static int eatables_length;
		static int tile_size;
		static sf::Vector2i offset;
		static Eatable *eatables;
		static	World *world;
		static bool areTheseSameColors(sf::Color &left,sf::Color &right);
		static void setImportantVariables(sf::RenderWindow *_window,World *_world);
		bool ate;
		bool tileDeleted;
		int type;
		int id;
		int width,height;
		void drawOnTexture();
		sf::Vector2i tile_pos;
		sf::Vector2f pos;
		void set(sf::Vector2i _tile_pos,char *_type);
		void update();
		Hitbox hitbox;
		void checkCollision();
	public:
		static void loadAllEatablesFromFile(char* path);
		static void setupAllEatables();
		static void updateAllEatables();
		static void checkCollsionsForAllEatables();
		static void loadAllEatables(char* path);
		static void drawAllEatables();
		static void respondToKeysAllEatables();
		static void setupEverythingForEatable(sf::RenderWindow *_window,World *_world);
		static void destroyEverythingForEatable();
		static void addEatable(sf::Vector2i _tile_pos,char *_type);
		
		//Hitbox hitbox;
		void setPosition(sf::Vector2f _pos);
		void setPosition(sf::Vector2i _tile_pos);
		
		Eatable();
		~Eatable();
		void draw();
		void getEated();
		void die();

};

#endif

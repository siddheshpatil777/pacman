#ifndef HITBOX_H
#define HITBOX_H
//#pragma comment(linker, "/STACK:2000000")
//#pragma comment(linker, "/HEAP:2000000")
//#include"SFML/System/Vector2.hpp"
#define GHOST 'g'
#define PACMAN 'p'
#define EATABLE 'e'
#include "main_defines.h"
#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"
#include <iostream>
#include <string.h>
#define MAX_PACMAN_HITBOXES 4
#define MAX_GHOST_HITBOXES 4
#define MAX_EATABLE_HITBOXES 250
//#define TILE_SIZE 16

using namespace std;
class Hitbox{
	private:
		static sf::RenderTexture hitbox_screen_texture;
		static sf::Sprite hitbox_screen_sprite;
		bool alive;
		int collided_with_eatable;
		int collided_with_ghost;
		int collided_with_pacman;
		void refresh();
		char type;
		static int max_hitboxes;
		static int eatables_length;
		static int pacmans_length;
		static int ghosts_length;
		static Hitbox **hitboxes_of_pacmans;
		static Hitbox **hitboxes_of_eatables;
		static Hitbox **hitboxes_of_ghosts;
		static sf::RenderWindow *window;
		sf::Vector2f *pos;
		sf::Vector2f size;
		int height,width;
		sf::Vector2i offset;
		sf::Color color;
		sf::RectangleShape box;
		int TYPE,owner_id;
		void registeringAddress();
		Hitbox* giveMeYourAddress();
	public:
		int getCollidedWithEatable();
		int getCollidedWithGhost();
		int getCollidedWithPacman();
		void doneWithEatable();
		void doneWithGhost();
		void doneWithPacman();
		sf::FloatRect hitbox;
		static void setupEverythingForHitboxes(sf::RenderWindow *_window,int _max_hitboxes);
		static void destroyEverythingForHitboxes();
		static void drawAllHitboxes();
		static void HandleHitboxes();
		void drawHitbox();
		static void printAllHitboxData();
		void setType(char t[]);
	//	Hitbox();
		Hitbox();
		void set(sf::Vector2f *pos,int h,int w,sf::Vector2i _offset,int _type);
		void setOwnerID(int id);
		~Hitbox();
	protected:
};

#endif


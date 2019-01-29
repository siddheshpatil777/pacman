//#pragma comment(linker, "/STACK:20000000")
//#pragma comment(linker, "/HEAP:20000000")
#ifndef WORLD_H
#define WORLD_H
//BASIC
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
using namespace std;
//SFML
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
//PROJECT
#include "text.h"
#include "main_defines.h"
#include "network.h"
#include "path.h"
#include "hitbox.h"
#include "tile.h"
#include "maze.h"
#include "node.h"
//#include "pacman.h"

//definations

const char main_world[100]={"images/world/maze_1.jpg"};
class World{
	private:
		void loadSoundsFromFile();
		static sf::Vector2i tileToRealCoords(int x,int y,int size);
		static bool areTheseSameColors(sf::Color &left,sf::Color &right);
		void setupForSound();
		void loadSound(char *_path);
		void destroyForSound();
		sf::Sound *all_sounds;
		sf::SoundBuffer *all_sound_buffers;
//		sf::Music *all_sound_buffers;
		int all_sounds_length;
		Maze maze;
		int rows,cols;
		sf::Vector2f world_offset;
		float world_scale;
		int height,width;
		sf::RenderWindow *window;
		sf::Texture texture;
		
	public:
		static sf::Texture *all_sprites;
		static int all_sprites_length;
		sf::Texture* getPointerToAllSprites();
		void requestToStopAllSounds();
		void requestToPlaySound(int id);
		void loadAllSprites(char *_path);
		int responseToRequestForTile(sf::Vector2i _tile_pos);
		sf::Sprite sprite;
		void displayPath();
		void displayPoints();
		void drawWorld();
		World(int h,int w,int blockSize,sf::RenderWindow *_window);
		bool isPathValid(sf::Vector2f a);
		~World();	
};
#endif

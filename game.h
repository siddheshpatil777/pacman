#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include"hitbox.h"
#include "pacman.h"
#include "network.h"
#include "ghost.h"
#include "eatable.h"
#include "node.h"
#include "world.h"
#include "MYCLASSES/dictionary.h"
#include "MYCLASSES/array.h"
#include <conio.h>
#include <windows.h>
using namespace std;
#define windowWidth 448
#define windowHeight 576
#define blockSize 32
#include "text.h"
#include "useful.h"
class Game{
	private:
		
		int FPS;
		sf::RenderWindow *window;
		World *world;
		sf::Event event;
	//	Pacman **pacmans;
		//Ghost **ghosts;
		//Eatable **eatables;//=new Pacman*[4];
	//	int pacmans_length;
	public:
		Game(sf::RenderWindow *win,World *wor);
		~Game();
		void addPacman();
		void gameLoop();	
		void startScreen();	
		void highScoreScreen();
};

#endif

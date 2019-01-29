#ifndef GHOST_H
#define GHOST_H
#define MAX_GHOSTS 4
#include "character.h"
#include "MYCLASSES/array.h"
#include "MYCLASSES/dictionary.h"
#include "node.h"
#include "pacman.h"
#include "useful.h"
#include"main_defines.h"
///
class Ghost : public Character{	
	private:
		Dictionary<Node*,Node*> nodeParents;
		void mainBehavior();
		void findNewPath();
		//
		static void clyde();
		static void blinky();
		static void inky();
		static void pinky();
		//
		static void setupBlinky();
		static void setupClyde();
		static void setupInky();
		static void setupPinky();
		int distance_to_end_future,distance_to_end_current;
		void moveInCage();
		bool in_cage;
		void whenPacmanIsKilled();
		Array<Node*> paths_future;
		Array<Node*> paths;
		int paths_index;
		int ghost_type;
		static sf::Texture* all_sprites;
		static int* textures_main;
		static int textures_length;
		void set(sf::RenderWindow *_window,World *_world);
		static sf::RenderTexture ghost_screen_layer;
		static sf::Sprite ghost_screen_tile; 
		void drawOnTexture();
		bool b;
		bool forward;
		int frequency;
		void checkCollision();
		void findShortestPath();
		void checkForFutureDirection();
	public:
		Array<Node*> *getPaths();
		Array<Node*> *getPathsFuture();
		void refreshPaths();
		void updatingPaths();
		void alligneToPath();
		void followPath();
		static void loadAllSpritesFromFile();
		static void moveAllGhosts();
		static void drawAllGhosts();
		static void respondToKeysAllGhosts();
		static void setupEverythingForGhost();
		static void destroyEverythingForGhost();
		static void checkCollisionForAllGhosts();
		static Ghost *ghosts;
		static int ghosts_length;
		void setDistanceToEnd(int d);
		static void addGhost(int _ghost_type,sf::RenderWindow *_window,World *_world);
		static void mainSetup();
		void draw();
		void respondToKeys();
		void resurect();
		void die();
		static void setupAllGhosts();
		Ghost();
		~Ghost();
	
};

#endif

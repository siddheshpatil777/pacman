
#ifndef PACMAN_H
#define PACMAN_H
#include "network.h"
#include "main_defines.h"
#include "node.h"
#include "character.h"
//#include "world.h"
#include "MYCLASSES/array.h"
//#include "dictionary/dictionary.h"
class Pacman : public Character{
	private:
		static sf::Texture *all_sprites;
	//	static Dictionary<sf::Vector2i> sprites_pos;
		static int* textures_main;
	//	static Array<int> textures_main;
		static int textures_length;
		int key_set;
		void set(sf::RenderWindow *_window,World *_world);
		static sf::RenderTexture pacman_screen_layer;
		static sf::Sprite pacman_screen_tile; 
		void drawOnTexture();
		bool justDied;
	public:
		static void loadAllSpritesFromFile();
		void checkCollision();
		static void checkCollsionsForAllPacmans();
		static void moveAllPacmans();
		static void drawAllPacmans();
		static void respondToKeysAllPacmans();
		static void setupEverythingForPacman();
		static void destroyEverythingForPacman();
		static Pacman *pacmans;
		static int pacmans_length;
		Pacman();
		static void addPacman(sf::RenderWindow *_window,World *_world);
		void draw();
		void respondToKeys();
		void resurect();
		void die();
		~Pacman();
};

#endif

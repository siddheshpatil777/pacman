#ifndef TILE_H
#define TILE_H
#define MAX_TILES 60
#include "SFML/Graphics.hpp"
#include<string.h>
#include<iostream>
using namespace std;
class Tile{
	private:
		static sf::RenderWindow *window;
		static sf::RenderTexture *offscreen_window;
		static void setParentPath(char p[]);
		static char parent_path[30];
		static Tile *tiles;
		static int tiles_length;
		void set(sf::Color _color,char _path[],char _name[],int _code);
		void setTexture();
		sf::Color color;
		int code;
		sf::Image image_data;
		sf::Texture texture_data;
		sf::Sprite sprite;
		char name[30];
	public:
		static void addTile(sf::Color _color,char _name[]);
		static void setupEveryThingForTile(sf::RenderWindow *_window,sf::RenderTexture *_offscreen_window,char p[]);
		static void destroyEveryThingForTile();
		static int getTileCodeByColor(sf::Color c);
		static sf::Texture getTextureByCode(int c);
		//static void getTileByCode(int id);
		static void drawAt(sf::Vector2f pos,int tile_code);
		Tile();
		~Tile();
	protected:
};

#endif

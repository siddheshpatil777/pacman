#ifndef TEXT_H
#define TEXT_H
#include "SFML/Graphics.hpp"
#include "main_defines.h"
#include "ctype.h"
#include <string.h>
#include <iostream>
using namespace std;
#define MAX_IMAGES 400
class Text{	
	static sf::RenderTexture text_screen_tile;
	static sf::Sprite text_screen_sprite;
	static sf::Sprite text_sprite;
	static int text_tile_size;
	static int images_length;
	static void splitData();
	static sf::Texture *images;
//	static char path[40];
	static sf::RenderWindow *window;
	static sf::Texture main_texture_tile;
	static sf::Image main_data;
//	sf::RenderTexture screen_data;
	
	char data[40];
	int color;
	sf::Vector2i pos;
public:
	sf::Sprite sprite;
	sf::Texture t;
	static void testAllCharacters();
	static void setupEveryThingForText(char *_path,sf::RenderWindow *_window);
	static void destroyEveryThingForText();
	static void drawTextToScreen(char *text,sf::Vector2i tile,int color);
	void drawTextToSprite();
	Text();
	void set(char data[] ,int color,sf::Vector2i pos);
	Text(char data[] ,int color,sf::Vector2i pos);
	void draw();
	void setColor(int color);
	void setPosition(sf::Vector2i pos);	
};
#endif

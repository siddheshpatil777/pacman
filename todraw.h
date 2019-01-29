#ifndef TODRAW_H
#define TODRAW_H
#include "SFML/Graphics.hpp"
class ToDraw  {
	public:
		sf::Vector2f pos;
		int id;
		ToDraw(){
			pos.x=pos.y=-1.0;
			id=-1;
		}
};
#endif

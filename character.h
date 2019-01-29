#ifndef CHARACTER_H
#define CHARACTER_H
#include "main_defines.h"

#define dtime 0.01
#include"world.h"
#include "SFML/Graphics.hpp"
#include "hitbox.h"
#include "node.h"
#include "path.h"
#include <math.h>
#include <iostream>
using namespace std;
class Character{
	private:
		void ifNearFutureNodeSetPosition();
		void updateCurrentNode();
		void makeSureFutureNodeIsNotCurrentNode();
		
		bool ifStopped();
		void printDirection();
		Node* isDirectionValid(char d);
		void printFutureDirection();
		void printPreviousDirection();
		float distance(sf::Vector2f p1,sf::Vector2f p2);
		float distance(sf::Vector2f p1,sf::Vector2i p2);
		sf::Vector2f future_position;
		void calculateFuturePosition(float multiplier);
		sf::Vector2f previous_position;
		char previous_direction,future_direction;
		void directionListUpdate();
		char getPreviousDirection();	
		void positionListUpdate(sf::Vector2f newPos);
		void setVelocityByDirection();
		void setVelocityByDirection(char d);
		void updatePositionByVelocity();
		void checkTunnelling();
		sf::Vector2f getPreviousPosition();
		Character& giveMeYourAddress();
		void updateFutureDirection();
		sf::Vector2f proximityToPoint();
		int q;
	protected:
		bool justMoved;
		
		//static in
		Node *current_node,*future_node,*previous_node;
		void setCurrentNode(Node *node);
		void setFutureNode(Node *node);
		void switchSwitchingVariable();
		static sf::Vector2i tileToRealCoords(int x,int y,int size);
		bool switchting_variable;
		int lives,score;
		sf::Sprite main_sprite;
		void setFutureDirection(char d);
		char getFutureDirection();
		void reverseDirectionCheck();
		int id;
		bool alive;
		Hitbox hitbox;
		sf::RenderWindow *window;
		World *world;
		sf::Vector2f pos;
		sf::Vector2f vel;
		sf::Vector2f acc;
		int width,height;
		char direction;
		float max_speed;
	public:
		void stop();
		Character(sf::RenderWindow *_window ,World *_world);
		Character();
		//virtual void draw();
		void setImportantVariables(sf::RenderWindow *_window,World *_world);
		void move();
		void setDirection(char dir);
		char getDirection();
		void setPosition(float x,float y);
		void setPosition(sf::Vector2f _pos);
		void setMaxSpeed(float speed);
		void setMaxSpeedByPercentage(int percent);
		float getMaxSpeed();
		sf::Vector2f getPosition();
		void printPosition(sf::Vector2f position);	
		Node *getFutureNode();
		Node *getCurrentNode();
			
	//	~Character();
	
};

#endif

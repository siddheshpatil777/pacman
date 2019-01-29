#ifndef NODE_H
#define NODE_H
//
#include "SFML/Graphics.hpp"
#include "main_defines.h"
//
//
#include<math.h>
#include<string.h>
#include<iostream>
#include<fstream>
using namespace std;
//

class Node{
	private:
		Node* _neighbours[4];
		int neighbours_id[4];
		void getNearestNeighbourDifferentNode();
		int id;
		void printNeighborData();
		void hereIsYourNeighbor(const int index);
		static void addPoint(int x ,int y, sf::Vector2i tile);
		static void addPoint(const sf::Vector2f &p, sf::Vector2i tile);
		static int rows,cols,tile_size;
		bool checkWhetherMultiple();
		static int doesThisPointExistWithTilePos(int tile_x,int tile_y);
		
		
		void setTilePos(sf::Vector2i tile);
		void set(int x,int y);
		void addOffsetToPosition();
		bool is_offset_added;
		sf::Vector2f pos;
		sf::Vector2i tile_pos;
		Node *neighbor_left,*neighbor_up,*neighbor_down,*neighbor_right;
		int d_neighbor_left,d_neighbor_up,d_neighbor_down,d_neighbor_right;
		int distanceHVOnly(Node Node);
		
	public:
		int getSimilarPointWithLeastDistance(char direction);
		int* getNeighboursId();
		char getDirectionOf(Node *_node);
		Node* getRandomNeighbourNode();
		Node** getNeighbours();
		Node* getNeighbour(char _direction);
		Node* getRandomNeighbourNodeButNotInOppositeDirection(char _direction);
		int getId();
		Node* doesNodeExistInThatDirection(char d);
		void setNeighbourInThatDirection(char d,Node *_node);
		Node* giveMeYourAddress(); 
		int getDistance(Node _node);
		int getDistance(Node *_node);
		static int getDistance( Node _node1,Node _node2);
		int getDistance( sf::Vector2f _pos);
		int getDistance(int n);
		static void printAllNeighborsData();
		static void assignNeighbors();
		static void printAllPointData();
		static void setCenterOffset(sf::Vector2f offset);
		static sf::Vector2f getPos(const int &i);
		static bool doesThisPointExistWithPos(sf::Vector2f _pos);
		sf::Vector2f getPos() const;
		sf::Vector2i getTilePos() const;
		static void displayAllPoints(sf::RenderWindow *window);
		static void displayAllPointsWithNumbers(sf::RenderWindow *window);
		static Node *nodes;
		static int nodes_length;
		static void setupEverythingForPoint(int r,int c,int t);
		static void destroyEverythingForPoint();
		static void addPointByTileCoord(int tile_x,int tile_y);
		static void addExtraPoints();
		Node();
		void set(sf::Vector2f p);
		Node(sf::Vector2f _pos);
		~Node();
};

#endif


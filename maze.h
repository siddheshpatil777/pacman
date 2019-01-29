#ifndef MAZE_H
#define MAZE_H
#define TILE_SIZE 16
//
#include "SFML/Graphics.hpp"
#include "tile.h"
#include "path.h"
#include "node.h"
//
#include<string.h>
#include <iostream>
using namespace std;
//
class Maze{
	private:
		//sf::RenderWindow* new_window;
		char pathForMazetemplate[50];
		static sf::RenderWindow* window;
		static sf::RenderTexture maze_texture;
		static sf::Texture main_texture;
		static sf::Sprite sprite;
		int maze_data[36][28];
		//sf::Sprite sprite_data[36][28];
		int height,width,rows,cols;
		sf::Image image;
		static void loadAllTiles();
	public:
		sf::Texture* getPointerToMazeTexture();
		static void setupEverythingForMaze(sf::RenderWindow* _window,char pathForTiles[]);
		static void destroyEverythingForMaze();
		void setMazeData(char _pathForMazetemplate[]);
		void printMazeDataCode();
		int getMazeDataByTileCoord(int i,int j);
		void updateMaze();
		void findPoints();
		void drawMaze();
		void findPaths();
		void set(int h,int w,int r,int c);
		Maze();
		Maze(int h,int w,int r,int c);
		~Maze();
	protected:
};

	

#endif

#ifndef PATH_H
#define PATH_H
///
#include"SFML/System/Vector2.hpp"
//#include"Node/impFunctions.h"
////
#include<string>
#include<stdio.h>
#include<math.h>
#include<fstream>
#include<iostream>
using namespace std;
///
#include"node.h"
//#include"point/usefull.h"
//
const char VERTICAL='v';
const char HORIZONTAL='h';
const char NONE='n';
#define MAX_PATHS 500
class Path{	
	private:
		char allign;
		//oldfunctions//static bool checkSimilarityWithPercentage(float a,float b,float alpha);
		//oldfunctions//static bool checkSimilarityWithvalue(float c,float d,float beta);
		sf::Vector2f start,end;
		//float coefficient_of_similarity;
		static int max_paths;
		static int paths_length;
		Path& giveMeYourAddress();
		void load(const sf::Vector2f &p1,const sf::Vector2f &p2);
	public:
		static void loadPathsFromFile(char *path);
	
		static Path *paths;
		static void setupEverythingForPath(int max);
		static void destroyEverythingForPath();
		static void addPath(const sf::Vector2f &p1,const sf::Vector2f &p2);
		static void addPathFromPointsIndex(const int &p1,const int &p2);
		static int getPathsLength();
		sf::Vector2f getStart() const;
		sf::Vector2f getEnd() const;
		static void displayAllPaths(sf::RenderWindow *window);
		Path();
		bool isItOnPath(sf::Vector2f Node);
		bool isItOnPath(float x,float y);
		void isDirectionValid(sf::Vector2f Node);
		~Path();
		
};

#endif

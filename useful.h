#ifndef USEFUL_H
#define USEFUL_H
#include <iostream>
using namespace std;
#include"MYCLASSES/array.h"
#include"MYCLASSES/dictionary.h"
#include"node.h"
class Useful{
	private:
	public:
		static void DijkstraAlgorithm(Dictionary<Node*,Node*> &nodeParents,Node *start, Node *end,int &distance_to_end,const char direction,const char future_direction);
		static setupEverythingForUseful();
		static destroyEverythingForUseful();
};

#endif

#include "useful.h"
//World *Useful::world;
//static Pacman *pacmans;
//static Ghost *ghosts;
/* TODO (#1#): ai for all
 */
//Dictionary<Node*,Node*> *Useful::nodeParents;
Useful::setupEverythingForUseful(){

}
Useful::destroyEverythingForUseful(){

}
void Useful::DijkstraAlgorithm(Dictionary<Node*,Node*> &nodeParents,Node* _start, Node* _end,int &distance_to_end,const char direction,const char future_direction){
	int start=_start->getId();
	int end=_end->getId();
	int length=Node::nodes_length;
	Array<Node*> unexploredNodes(length);
	Dictionary<Node*,int> distances(length);
	Dictionary<Node*,Node**>neighbours(length);
	//nodeParents.clear(NULL,NULL);
	for(int i=0;i<length;i++){
		Node *temp=Node::nodes[i].giveMeYourAddress();
		nodeParents.add(temp,NULL);
		unexploredNodes.push(temp);
		distances.add(temp,INT_MAX);
		neighbours.add(temp,Node::nodes[i].getNeighbours());
	}
	/*
	Node *tempForLater;
	if(direction=='u'){
		tempForLater=_start->doesNodeExistInThatDirection(DOWN);
		_start->setNeighbourInThatDirection(DOWN,NULL);
	}
	else if(direction=='d'){
		tempForLater=_start->doesNodeExistInThatDirection(UP);
		_start->setNeighbourInThatDirection(UP,NULL);
	}
	else if(direction=='l'){
		tempForLater=_start->doesNodeExistInThatDirection(RIGHT);
		_start->setNeighbourInThatDirection(RIGHT,NULL);
	}
	else if(direction=='r'){	
		tempForLater=_start->doesNodeExistInThatDirection(LEFT);
		_start->setNeighbourInThatDirection(LEFT,NULL);
	}
	*/
	//
	/*
	Node *tempForLater2;
	//
	if(direction=='u'){
		tempForLater2=_start->doesNodeExistInThatDirection(UP);
		if(tempForLater2!=NULL){
			tempForLater2->setNeighbourInThatDirection(DOWN,NULL);
		}
	}
	else if(direction=='d'){
		tempForLater2=_start->doesNodeExistInThatDirection(DOWN);
		if(tempForLater2!=NULL){
			tempForLater2->setNeighbourInThatDirection(UP,NULL);
		}
	}
	else if(direction=='l'){
		tempForLater2=_start->doesNodeExistInThatDirection(LEFT);
		if(tempForLater2!=NULL){
			tempForLater2->setNeighbourInThatDirection(RIGHT,NULL);
		}
	}
	else if(direction=='r'){	
		tempForLater2=_start->doesNodeExistInThatDirection(RIGHT);
		if(tempForLater2!=NULL){
			tempForLater2->setNeighbourInThatDirection(LEFT,NULL);
		}
	}
	*/
	
	Node* current=_start;
	distances[_start]=0;
	while(unexploredNodes.length()>0){
		current=distances.minElementKeyUsingValuesOf(unexploredNodes);
		if(current==_end){
		//	cout<<"path found"<<"\n";
		//	cout<<"found path"<<distances[_end]<<"\n";
		//	nodeParents[INDEX].print();
	//		cout<<"the distatance to end = "<<distances[_end]<<"\n";
			//return nodeParents;
			distance_to_end=distances[_end];
		/*
			if(direction=='u'){
				_start->setNeighbourInThatDirection(DOWN,tempForLater);
			}
			else if(direction=='d'){
				_start->setNeighbourInThatDirection(UP,tempForLater);
			}
			else if(direction=='l'){
				_start->setNeighbourInThatDirection(RIGHT,tempForLater);
			}
			else if(direction=='r'){	
				_start->setNeighbourInThatDirection(LEFT,tempForLater);
			}
		*/
			//
			//
			/*
			if(direction=='u'){
				if(tempForLater2!=NULL){
					tempForLater2->setNeighbourInThatDirection(DOWN,_start);
				}
			}
			else if(direction=='d'){
				if(tempForLater2!=NULL){
					tempForLater2->setNeighbourInThatDirection(UP,_start);
				}
			}
			else if(direction=='l'){
				if(tempForLater2!=NULL){
					tempForLater2->setNeighbourInThatDirection(RIGHT,_start);
				}
			}
			else if(direction=='r'){	
				if(tempForLater2!=NULL){
					tempForLater2->setNeighbourInThatDirection(LEFT,_start);
				}
			}
			*/
			break;
		}
		unexploredNodes.remove(current);
		Node **neighbours_id=neighbours[current];
		int dist;
		for(int j=0;j<4;j++){
			Node* node =neighbours_id[j];
			if(node!=NULL){
				dist=distances[current]+current->getDistance(node);
				if(dist<distances[node]){
					distances[node]=dist;
					nodeParents[node]=current;
				}	
			}				
		}	
	}/*
	for(int k=0;k<nodeParents.length();k++){
				if(nodeParents.getKey(k)!=NULL){
					cout<<nodeParents.getKey(k)->getId();
				}
				else{
					cout<<" NULL ";
				}
				cout<<" : ";
				if(nodeParents.getValue(k)!=NULL){
					cout<<nodeParents.getValue(k)->getId();
				}
				else{
					cout<<" NULL ";
				}
				cout<<"\n";
			}
			*/
}

/*
for(int j=0;j<4;j++){
			if(neighbours[j]!=NULL){
				dist= distances[current]+Node::nodes[current].getDistance(*neighbours[j]);
				if(dist <distances[neighbours[j]->getId()]){
					distances[neighbours[j]->getId()]=dist;
					prev[prev_length++]=neighbours[j]->getId();
				}
			}
		}
*/

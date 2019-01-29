#include "path.h"
int Path::max_paths;
int Path::paths_length;
Path* Path::paths;

Path::Path(){	
	//coefficient_of_similarity=4.0;
	//paths[paths_length++]=giveMeYourAddress();
}
/*
bool Path::checkSimilarityWithPercentage(float a,float b,float alpha){
	if(-1*(a*alpha/100)<= b && b<=(a*alpha/100)){
		return true;
	}
	else{
		return false;
	}
}

bool Path::checkSimilarityWithvalue(float c,float d,float beta){
	if(c-beta<= d && d <=c+beta){
		return true;
	}
	else{
		return false;
	}
}
*/
void Path::load(const sf::Vector2f &p1,const sf::Vector2f &p2){
	start.x=p1.x;
	start.y=p1.y;
	end.x=p2.x;
	end.y=p2.y;
	if(start.x==end.x){
		allign=VERTICAL;
	}
	else if(start.y==end.y){
		allign=HORIZONTAL;
	}
	else{
		allign=NONE;
	}
}
bool Path::isItOnPath(sf::Vector2f Node){
	float sim=4.0;
	//  <    <= old
	if(allign==HORIZONTAL){
		if(Node.y==start.y){//checkSimilarityWithvalue(Node.y,start.y,sim)){
			if(start.x<end.x){
				if(start.x<=Node.x && Node.x<=end.x){
					return true;
					//	cout<<"true31"<<"\n";
				}
				else{
					return false;
					//cout<<"false12"<<"\n";
					}			
				}
			else if(start.x>end.x){
				if(start.x>=Node.x && Node.x>=end.x){
					return true;
				//	cout<<"true72"<<"\n";
				}
				else{
					return false;
				//	cout<<"false7"<<"\n";
				}
			}
			else{
				return false;
			///	cout<<"false4"<<"\n";
			}
		}
		else{
			return false;
		}
	}
	else if(allign==VERTICAL){
		if(Node.x==end.x){//checkSimilarityWithvalue(Node.x,end.x,sim)){
			if(start.y<end.y){
				if(start.y<=Node.y && Node.y<=end.y ){
			//		cout<<"truethe one"<<"\n";
					return true;
				}
				else{
			///		cout<<"false the one"<<"\n";
					return false;	
				}
			}
			else if(start.y>end.y){
				if(start.y>=Node.y && Node.y>=end.y ){
			//		cout<<"true3"<<"\n";
						return true;
				}
				else{
			//		cout<<"false3"<<"\n";
					return false;
				}
			}
			else{
			//	cout<<"false6"<<"\n";
			//	cout<<"allign"<<allign<<"\n";
			//	cout<<"path is x:"<<start.x<<" y:"<<start.y<<" to "<<"path x:"<<end.x<<" y:"<<end.y<<"\n";
				return false;
			}
		}
		else{
			return false;
		}
	}
}
/*
bool Path::isItOnPath(float x,float y){
	sf::Vector2f Node;
	Node.x=x;
	Node.y=y;
	
	if(allign==HORIZONTAL){
		if(checkSimilarityWithvalue(Node.y,start.y,coefficient_of_similarity)){
			if(start.x<end.x){
				if(start.x<=Node.x && Node.x<=end.x){
					return true;
					//	cout<<"true31"<<"\n";
					}
				else{
					return false;
					//cout<<"false12"<<"\n";
					}			
				}
			else if(start.x>end.x){
				if(start.x>=Node.x && Node.x>=end.x){
					return true;
				//	cout<<"true72"<<"\n";
				}
				else{
					return false;
				//	cout<<"false7"<<"\n";
				}
			}
			else{
				return false;
			///	cout<<"false4"<<"\n";
			}
		}
		else{
			return false;
		}
	}
	else if(allign==VERTICAL){
		if(checkSimilarityWithvalue(Node.x,end.x,coefficient_of_similarity)){
			if(start.y<end.y){
				if(start.y<=Node.y && Node.y<=end.y ){
			//		cout<<"truethe one"<<"\n";
					return true;
				}
				else{
			///		cout<<"false the one"<<"\n";
					return false;	
				}
			}
			else if(start.y>end.y){
				if(start.y>=Node.y && Node.y>=end.y ){
			//		cout<<"true3"<<"\n";
						return true;
				}
				else{
			//		cout<<"false3"<<"\n";
					return false;
				}
			}
			else{
			//	cout<<"false6"<<"\n";
			//	cout<<"allign"<<allign<<"\n";
			//	cout<<"path is x:"<<start.x<<" y:"<<start.y<<" to "<<"path x:"<<end.x<<" y:"<<end.y<<"\n";
				return false;
			}
		}
		else{
			return false;
		}
	}
}
*/
Path::~Path(){
}
sf::Vector2f Path::getStart() const{
	return start;
}
sf::Vector2f Path::getEnd() const{
	return end;
}
void Path::setupEverythingForPath(int max){
	cout<<"Everything SETUP for path"<<"\n";
	max_paths=max;
	paths_length=0;
	paths=new Path[MAX_PATHS];
}
void Path::destroyEverythingForPath(){
	delete [] paths;
	cout<<"Everything DESTROYED for path"<<"\n";
}
int Path::getPathsLength(){
	return paths_length;
}
Path& Path::giveMeYourAddress(){
	return *this;
}
void Path::addPath(const sf::Vector2f &p1,const sf::Vector2f &p2){
	paths[paths_length++].load(p1,p2);
}
void Path::addPathFromPointsIndex(const int &p1,const int &p2){
	if(p1>=65||p2>=65){
		cout<<"p1 and p2 are very high "<<"( p1 : "<<p1<<" p2 : "<<p2<<")"<<"\n ";
	}
	if(0<=p1 && 0<=p2){
		paths[paths_length].load(Node::getPos(p1),Node::getPos(p2));
		paths_length++;
	//	cout<<"path created from ( x:"<<Node::getPos(p1).x<<" , y:"<<Node::getPos(p1).y<<") to ( x:"<<Node::getPos(p2).x<<" , y:"<<Node::getPos(p2).y<<")"<<"\n";
		cout<<"path created from tile ( "<<p1<<" th , y:"<<p2<<" th )"<<"\n";
	} 
	else{
		cout<<"path cannot be added index less than 1"<<"\n";
	}
}
void Path::displayAllPaths(sf::RenderWindow *window){
	for(int i=0;i<paths_length;i++){
		sf::Vertex line[] ={
    		sf::Vertex(paths[i].getStart()),
    		sf::Vertex(paths[i].getEnd())
		};
		window->draw(line, 2, sf::Lines);		
	}
	
	//window->draw(shape);
}

void  Path::loadPathsFromFile(char *path){
	fstream fin(path,ios::in);
	if(!fin){
		cout<<"Error file for paths does not exist"<<"\n";
	}
	else{
		char point1[3],point2[3];
		char data[6];
		while(!fin.eof()){
			fin.getline(data,8,'\n');
			point1[0]=data[0];
			point1[1]=data[1];
			point1[2]='\0';
			point2[0]=data[3];
			point2[1]=data[4];
			point2[2]='\0';
			
		//	addPathFromPointsIndex(to_int(point1),to_int(point2));
			//puts(data);
			//cout<<"x : "<<x[0]<<x[1]<<" y : "<<y[0]<<y[1]<<"\n";
			//cout<<"Node 1 :"<<to_int(point1)<<" , Node 2 : "<<to_int(point2)<<"\n";
		}
	}
}

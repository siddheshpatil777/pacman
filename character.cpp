#include "character.h"


int integer(float x){
	int y=x;
	return y;
}
//float Character::dtime=0.01667;
void Character::switchSwitchingVariable(){
	switchting_variable=!switchting_variable;
}
Character::Character(){
	width=height=32;
	switchting_variable=false;
	direction=DOWN;
	future_direction=DOWN;
	pos.x=(16.0*1)+8.0;
	pos.y=(16.0*4)+8.0;
	positionListUpdate(pos);
	positionListUpdate(pos);
	max_speed=230.0;
	vel.x=0.0;
	q=0;
	vel.y=0.0;
	acc.x=0.0;
	acc.y=0.0;
	alive=true;
	previous_direction=NONE;
	///
	hitbox.set(&pos,height,width,sf::Vector2i(0,0),0);
	//
	previous_node=Node::nodes[0].giveMeYourAddress();
	current_node=Node::nodes[0].giveMeYourAddress();
	future_node=Node::nodes[1].giveMeYourAddress();
	

}
Character::Character(sf::RenderWindow *_window,World *_world){
	width=height=32;
	world=_world;
	window=_window;
	direction=DOWN;
	future_direction=DOWN;
	pos.x=(16.0*1)+8.0;
	pos.y=(16.0*4)+8.0;
	positionListUpdate(pos);
	positionListUpdate(pos);
	max_speed=230.0;
	vel.x=0.0;
	vel.y=0.0;
	acc.x=0.0;
	acc.y=0.0;
	alive=true;
	score=0;
	previous_direction=NONE;
	///
	hitbox.set(&pos,4,4,sf::Vector2i(6,6),0);
	//
	previous_node=Node::nodes[0].giveMeYourAddress();
	current_node=Node::nodes[0].giveMeYourAddress();
	future_node=Node::nodes[1].giveMeYourAddress();
}
void Character::setImportantVariables(sf::RenderWindow *_window,World *_world){
	world=_world;
	window=_window;
}

/*
bool Character::isPathValid(sf::Vector2f postocheck){
	int i=postocheck.y,j=postocheck.x;
	return (world->path[world->width*i+j]);
}
bool Character::isPathValid(int x,int y){
	return (world->path[world->width*y+x]);
}
bool Character::isPathValid(float x,float y){
	int i=y,j=x;
	return (world->path[world->width*i+j]);
}
*/
sf::Vector2f Character::getPosition(){
	return pos;
}
void Character::printPosition(sf::Vector2f position){
	cout<<"position x:"<<position.x<<" y:"<<position.y<<"\n";
}
void Character::setPosition(float x,float y){
	pos.x=x;
	pos.y=y;
}
void Character::setCurrentNode(Node *node){
	current_node=node;
}
void Character::setFutureNode(Node *node){
	future_node=node;
}
void Character::setPosition(sf::Vector2f _pos){
	pos=_pos;
}
void Character::setDirection(char dir){
	direction=dir;
}
char Character::getDirection(){
	return direction;
}
void Character::setMaxSpeed(float speed){
	max_speed=speed;
}
float Character::getMaxSpeed(){
	return max_speed;
}
Character& Character::giveMeYourAddress(){
	return *this;
}
void Character::printPreviousDirection(){
	cout<<"PREVIOUS Direction "<<previous_direction<<"\n";
}
void Character::printDirection(){
	cout<<"Direction "<<direction<<"\n";
}
void Character::printFutureDirection(){
	cout<<"future direction "<<future_direction<<"\n";
}
void Character::positionListUpdate(sf::Vector2f newPos){
	previous_position=newPos;
}
sf::Vector2f Character::getPreviousPosition(){
	return previous_position;
}
sf::Vector2i Character::tileToRealCoords(int x,int y,int size){
	return sf::Vector2i(x*size,y*size);
}
void Character::directionListUpdate(){
//	if(previous_direction!=direction){
		previous_direction=direction;
		
//	}
	
}
char Character::getPreviousDirection(){
	return previous_direction;
}
//Character::~Character(){}
void Character::stop(){
//	direction==NO;
	vel.x=0.0;
	vel.y=0.0;
//	future_direction=NO;
}
void Character::setVelocityByDirection(){
	if(direction==UP){
		vel.x=0.0;
		vel.y=-1*max_speed;
		//future_direction=UP;
	}
	else if(direction==DOWN){
		vel.x=0.0;
		vel.y=1*max_speed;
		//future_direction=DOWN;
	}
	else if(direction==LEFT){
		vel.x=-1*max_speed;
		vel.y=0.0;
		//future_direction=LEFT;
	}
	else if(direction==RIGHT){	
		vel.x=max_speed;
		vel.y=0.0;
		//future_direction=RIGHT;
	}
	else if(direction==NO){	
		vel.x=0.0;
		vel.y=0.0;
	}
}
void Character::setVelocityByDirection(char d){
	if(d==UP){
		vel.x=0.0;
		vel.y=-1*max_speed;
		//future_direction=UP;
	}
	else if(d==DOWN){
		vel.x=0.0;
		vel.y=1*max_speed;
		//future_direction=DOWN;
	}
	else if(d==LEFT){
		vel.x=-1*max_speed;
		vel.y=0.0;
		//future_direction=LEFT;
	}
	else if(d==RIGHT){	
		vel.x=max_speed;
		vel.y=0.0;
		//future_direction=RIGHT;
	}
	else if(d==NO){	
		vel.x=0.0;
		vel.y=0.0;
	}
	//setFutureDirection();
}
void Character::updatePositionByVelocity(){
	pos.x+=(vel.x*dtime);
	pos.y+=(vel.y*dtime);
//	if(direction==UP || direction==LEFT){pos.x=ceil(pos.x);pos.y=ceil(pos.y);}
//	else{pos.x=floor(pos.x);pos.y=floor(pos.y);}
}

float Character::distance(sf::Vector2f p1,sf::Vector2f p2){
	return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

Node* Character::isDirectionValid(char d){
	Node* temp=current_node->doesNodeExistInThatDirection(d);
	if(temp==NULL){
		//cout<<"next node does not exist"<<"\n";
		return temp;
	}
	return temp;
}
bool Character::ifStopped(){
	return (pos==future_position);
}
void Character::makeSureFutureNodeIsNotCurrentNode(){
	if(future_node==current_node){
		future_node=NULL;
	}
}
void Character::ifNearFutureNodeSetPosition(){
	
	
}
char Character::getFutureDirection(){
	return future_direction;
}
void Character::reverseDirectionCheck(){
	if((direction=='l' && future_direction=='r')||(direction=='u' && future_direction=='d')||(direction=='r' && future_direction=='l')||(direction=='d' && future_direction=='u')){
		Node* temp=future_node;
		future_node=current_node;
		current_node=temp;
		direction=future_direction;	
	}
}
void Character::move(){
	q++;
	if(q>1){
		q=0;
		switchSwitchingVariable();
	}
	//WORKS LIKE BUTTER
//	printPreviousDirection();
//	printDirection();
//	printFutureDirection();

	if(future_node!=NULL){
		if(distance(pos,future_node->getPos())<=2.0){
			pos=future_node->getPos();
			previous_node=current_node;
			current_node=future_node;
			future_node=isDirectionValid(future_direction);
			justMoved=true;
			
			if(future_node!=NULL){
				direction=future_direction;
				setVelocityByDirection(direction);
				updatePositionByVelocity();
			}
			else{
				pos=current_node->getPos();
				stop();
			}		
		}
		else{
			setVelocityByDirection(direction);
			updatePositionByVelocity();
		}
	}
	else if(future_node==NULL){
		direction='n';
		if(current_node!=NULL){
			if(distance(pos,current_node->getPos())<=6.0){
				stop();
				pos=current_node->getPos();
				future_node=isDirectionValid(future_direction);
				if(future_node!=NULL){
					direction=future_direction;
					setVelocityByDirection(direction);
					updatePositionByVelocity();
				}
				else{
					if(direction==future_direction){
						pos=current_node->getPos();
						stop();
					//	cout<<"reached required else if"<<"\n";
					//	direction=getPreviousDirection();
					//	setVelocityByDirection(direction);
					//	future_node=isDirectionValid(direction);
					///	updatePositionByVelocity();
					}
					else{
					//	cout<<"reached required else else"<<"\n";
						
						direction=getPreviousDirection();
						setVelocityByDirection(direction);
						future_node=isDirectionValid(direction);
						updatePositionByVelocity();
						if(direction==future_direction){
							pos=current_node->getPos();
							stop();
						}
						//pos=current_node->getPos();
					}
				}
			}
		}
		else{
			
		}
	
	}
	
	positionListUpdate(pos);
	if(future_node!=NULL){
		directionListUpdate();
	}
//	cout<<sf::Keyboard::Right<<"\n";
//	pos=getPreviousPosition();
//	direction=getPreviousDirection();
//	printPosition(pos);
	/*
	if(current_node!=NULL){
		cout<<"current_node "<<current_node->getId()<<"\n";
	}
	else{
		cout<<"current_node NULL"<<"\n";
	}
	if(future_node!=NULL){
		cout<<"future_node "<<future_node->getId()<<"\n";
	}
	else{
		cout<<"future_node NULL"<<"\n";
	}
	*/
}
void Character::checkTunnelling(){
	if(current_node==&Node::nodes[66]){
		current_node=&Node::nodes[67];
		pos=current_node->getPos();
		future_node=&Node::nodes[64];
		direction=RIGHT;	
	}
}
void Character::updateFutureDirection(){
	if(previous_direction!=direction){
		future_direction=direction;
	}	
}
void Character::setFutureDirection(char d){
	future_direction=d;
}
void Character::setMaxSpeedByPercentage(int percent){
	max_speed=float(percent)*MAX_SPEED/100;
}
Node *Character::getFutureNode(){
	return future_node;
}
Node *Character::getCurrentNode(){
	return current_node;
}

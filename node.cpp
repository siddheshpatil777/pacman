#include "node.h"

int to_int(char *value){
	int answer=0;
	int temp=0;
	char a;
	int length=strlen(value);
	for(int i=0;i<length;i++){
		char a=value[i]-48;
		temp=a;
		answer+=temp*pow(10,length-1-i);
	}
	return answer;
}

Node *Node::nodes;
int Node::nodes_length;
int Node::cols;
int Node::rows;
int Node::tile_size;

//int Node::neighbours_id[4];
//sf::Vector2f Node::center_offset_from_origin;
void Node::setCenterOffset(sf::Vector2f offset){
//	center_offset_from_origin.x=offset.x;
//	center_offset_from_origin.y=offset.y;
}
Node::Node(){
	neighbours_id[0]=neighbours_id[1]=neighbours_id[2]=neighbours_id[3]=-1;
	_neighbours[0]=_neighbours[1]=_neighbours[2]=_neighbours[3]=NULL;
	is_offset_added=false;
	//Node** _neighbours=new Node*[4];
	neighbor_left=NULL;
	neighbor_up=NULL;
	neighbor_down=NULL;
	neighbor_right=NULL;
	d_neighbor_left=d_neighbor_up=d_neighbor_down=d_neighbor_right=-1;
}
Node::~Node(){
	//delete [] _neighbours;
}
void Node::printNeighborData(){
	cout<<"Thiss guy is  at"<<giveMeYourAddress()<<"\n";
	cout<<"neighbor_left at"<<neighbor_left<<"\n";
	cout<<"neighbor_up at"<<neighbor_up<<"\n";
	cout<<"neighbor_down at"<<neighbor_down<<"\n";
	cout<<"neighbor_right at"<<neighbor_right<<"\n";
}
void Node::printAllNeighborsData(){
	for(int i=0;i<nodes_length;i++){
		nodes[i].printNeighborData();
	}
}
bool Node::checkWhetherMultiple(){
	int x=pos.x;
	int y=pos.y;
	return ((x%tile_size==0) || (y%tile_size==0));
}
int Node::distanceHVOnly(Node Node){
	return -1;//(abs(Node.getPos().x-pos.x)+abs(Node.getPos().y-pos.y));
}
sf::Vector2f Node::getPos(const int &i){
	return nodes[i].pos;
}
sf::Vector2f Node::getPos() const{
	return pos;
}
sf::Vector2i Node::getTilePos() const{
	return tile_pos;
}
void Node::setupEverythingForPoint(int r=36,int c=28,int t=16){
	cout<<"Every Thing Set UP FOR Node"<<"\n";
	rows=r;	
	cols=c;
	tile_size=t;
	nodes_length=0;
	nodes=new Node[MAX_NODES];
	if (!nodes){
   		cout << " nodes: Memory allocation failed"<<"\n";
	}
	else{
		cout << "nodes: Memory succesfully  allocated "<<"\n";
	}
	
}
void Node::addOffsetToPosition(){
	if(is_offset_added==false){
	//	cout<<"Offset addeed to Node number "<<nodes_length<<"\n";
		pos.x=pos.x+MAIN_OFFSET_FROM_DISPLAY_X;
		pos.y=pos.y+MAIN_OFFSET_FROM_DISPLAY_Y;
		is_offset_added=true;
	}
	else{
		//cout<<"CANNOT ADD Offset already added"<<nodes_length<<"\n";
	}
	
}
void Node::set(sf::Vector2f p){
	pos.x=p.x;
	pos.y=p.y;
}
void Node::destroyEverythingForPoint(){
	delete [] nodes;
	cout<<"Every Thing DestOYEDD FOR Node"<<"\n";
}
void Node::addPoint(const sf::Vector2f &p, sf::Vector2i tile){
	nodes[nodes_length].setTilePos(tile);
	nodes[nodes_length].set(p);
	nodes[nodes_length].addOffsetToPosition();
	nodes[nodes_length].id=nodes_length;
	nodes_length++;
}
void Node::addPoint(int x ,int y, sf::Vector2i tile){
	nodes[nodes_length].setTilePos(tile);
	nodes[nodes_length].set(sf::Vector2f(x,y));
	nodes[nodes_length].addOffsetToPosition();
	nodes[nodes_length].id=nodes_length;
	nodes_length++;
}
void Node::addPointByTileCoord(int tile_x,int tile_y){
	int x=tile_x*tile_size;
	int y=tile_y*tile_size;
	addPoint(x,y,sf::Vector2i(tile_x,tile_y));
}
void Node::setTilePos(sf::Vector2i tile){
	tile_pos.x=tile.x;
	tile_pos.y=tile.y;
}
int Node::getId(){
	return id;
}
void Node::getNearestNeighbourDifferentNode(){
	int x=pos.x;int y=pos.y;
	x=x/TILE_SIZE;
	y=y/TILE_SIZE;	
	int index=doesThisPointExistWithTilePos(x,y);
	Node* temp;
	if(index!=-1){
		temp=nodes[index].giveMeYourAddress();
		sf::Vector2f displacement=pos-getPos(index);
		if(displacement.x>0 && displacement.y==0){
			_neighbours[0]=neighbor_left=nodes[index].giveMeYourAddress();
			neighbours_id[0]=nodes[index].getId();
			//
			_neighbours[1]=neighbor_right=nodes[index].neighbor_right;
			neighbours_id[1]=neighbor_right->getId();
		}
		else if(displacement.x==0 && displacement.y>0){
			_neighbours[2]=neighbor_up=nodes[index].giveMeYourAddress();
			neighbours_id[2]=neighbor_up->getId();
			//
			_neighbours[3]=neighbor_down=nodes[index].neighbor_down;
			neighbours_id[3]=neighbor_down->getId();
		}
	}
	else{
		cout<<"ERROR"<<"\n";
	}
	
}
int Node::doesThisPointExistWithTilePos(int tile_x,int tile_y){
	int index=-1;
	for(int i=0;i<nodes_length;i++){
		if(nodes[i].tile_pos.x==tile_x && nodes[i].tile_pos.y==tile_y){
			return i;
		}
	}
	return index;
}
bool Node::doesThisPointExistWithPos(sf::Vector2f _pos){
	for(int i=0;i<nodes_length;i++){
		if(nodes[i].pos.x==_pos.x && nodes[i].pos.y==_pos.y){
			return true;
		}
	}
	return false;
}
int Node::getSimilarPointWithLeastDistance(char direction){
	if(direction=='u'){
		int index=-1;
		for(int i=tile_pos.y-1;i>=0;i--){
			index=doesThisPointExistWithTilePos(tile_pos.x,i);
		//	cout<<"Second LOOP ^^^for tile x: "<<tile_pos.x<<", y : "<<i<<"  ^^^"<<"\n";
			if(index!=-1){
				return index;
			}
		}
	}
}
void Node::printAllPointData(){
	cout<<"POINT_DATA :"<<"\n";
	for(int i=0;i<nodes_length;i++){
		cout<<i<<": position=>( x: "<<nodes[i].pos.x<<" , y: "<<nodes[i].pos.y<<" ) tile=>( x: "<<nodes[i].tile_pos.x<<" , y: "<<nodes[i].tile_pos.y<<" )"<<"\n";
	}
}
void Node::displayAllPoints(sf::RenderWindow *window){
	int width=1;
	sf::CircleShape shape(width);
	sf::Color color(255,201,14,250);
	shape.setFillColor(color);	
	for(int i=0;i<nodes_length;i++){
		shape.setPosition(nodes[i].pos.x-2*width,nodes[i].pos.y-2*width);
		window->draw(shape);		
	}
}
char* str(int value){
	static char new_answer[10];
	if(value!=0){
		char answer[10];
	int i = 0;
	while(value!=0){
		int temp=value%10;
		value=value/10;
		char a=temp+48;
		answer[i++]=a;	
	}
	answer[i]='\0';
	//puts(answer);
	
	for(i=0;i<strlen(answer);i++){
		new_answer[i]=answer[strlen(answer)-1-i];
	}
	new_answer[i]='\0';
	//puts(new_answer);
	return new_answer;
	}
	else{
		strcpy(new_answer,"0");
		return new_answer;
	}
	
}
void Node::displayAllPointsWithNumbers(sf::RenderWindow *window){
	sf::Font font;
	// Load it from a file
	if (!font.loadFromFile("comicsansms.ttf"))
	{
		cout<<"Error could not load font"<<"\n";
    // error...
	}
	sf::Text text("hello",font);
	//to_string(1+2+4+7+14)
	text.setCharacterSize(24);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color::Red);
	sf::Vector2i o(4,10);
	//sf::CircleShape shape(width);
	//sf::Color color(255,201,14,250);
	for(int i=0;i<nodes_length;i++){
		text.setString(str(i));
		text.setPosition(nodes[i].pos.x-o.x,nodes[i].pos.y-o.y);	
		window->draw(text);		
	}
}
Node* Node::giveMeYourAddress(){
	return this;
}
Node* Node::doesNodeExistInThatDirection(char d){
	if(d=='u'){
		return neighbor_up;
	}
	else if(d=='d'){
		return neighbor_down;
	}
	else if(d=='l'){
		return neighbor_left;
	}
	else if(d=='r'){	
		return neighbor_right;
	}
	else{
		return NULL;
	}
}
void Node::setNeighbourInThatDirection(char d,Node *_node){
	if(d=='u'){
		neighbor_up=_node;
	}
	else if(d=='d'){
		neighbor_down=_node;
	}
	else if(d=='l'){
		neighbor_left=_node;
	}
	else if(d=='r'){	
		neighbor_right=_node;
	}
}
void Node::hereIsYourNeighbor(const int index){
	sf::Vector2f displacement=nodes[index].getPos()-pos;
	if(displacement.x>0 && displacement.y==0){
		_neighbours[0]=neighbor_right=nodes[index].giveMeYourAddress();
		neighbours_id[0]=nodes[index].getId();
	//	d_neighbor_right;
	}
	else if(displacement.x<0 && displacement.y==0){
		_neighbours[1]=neighbor_left=nodes[index].giveMeYourAddress();
		neighbours_id[1]=nodes[index].getId();
	//	d_neighbor_left,
	}
	else if(displacement.x==0 && displacement.y>0){
		_neighbours[2]=neighbor_down=nodes[index].giveMeYourAddress();
		neighbours_id[2]=nodes[index].getId();
	//	,d_neighbor_down,
	}
	else if(displacement.x==0 && displacement.y<0){
		_neighbours[3]=neighbor_up=nodes[index].giveMeYourAddress();
		neighbours_id[3]=nodes[index].getId();
	//	d_neighbor_up
	}
}
Node* Node::getRandomNeighbourNode(){
	if(neighbor_up!=NULL){
		return neighbor_up;
	}
	else if(neighbor_down!=NULL){
		return neighbor_down;
	}
	else if(neighbor_left!=NULL){
		return neighbor_left;
	}
	else if(neighbor_right!=NULL){	
		return neighbor_right;
	}
	else{
		return NULL;
	}
}
Node* Node::getRandomNeighbourNodeButNotInOppositeDirection(char _direction){
	if(_direction=='u'){
		if(neighbor_left!=NULL){
			return neighbor_left;
		}
		else if(neighbor_right!=NULL){	
			return neighbor_right;
		}
	}
	else if(_direction=='l'){
		if(neighbor_up!=NULL){
		return neighbor_up;
		}
		else if(neighbor_down!=NULL){
			return neighbor_down;
		}
	}
	else if(_direction=='r'){
		if(neighbor_up!=NULL){
			return neighbor_up;
		}
		else if(neighbor_down!=NULL){
			return neighbor_down;
		}
	}
	else if(_direction=='d'){
		if(neighbor_left!=NULL){
			return neighbor_left;
		}
		else if(neighbor_right!=NULL){	
			return neighbor_right;
		}
	}
}
void Node::assignNeighbors(){
	int length=0;
	char path[20]="data/paths.txt";
	fstream fin(path,ios::in);
	if(!fin){
		cout<<"Error file for paths does not exist"<<"\n";
	}
	else{
		char point1[3],point2[3];
		char data[6];
		while(!fin.eof()){
			fin.getline(data,8,'\n');
			point1[0]=data[0];point1[1]=data[1];point1[2]='\0';
			point2[0]=data[3];point2[1]=data[4];point2[2]='\0';
			////
			nodes[to_int(point1)].hereIsYourNeighbor(to_int(point2));
			length++;
		}
	}
	fin.close();
	fin.open(path,ios::in);
	if(!fin){
		cout<<"Error file for paths does not exist"<<"\n";
	}
	else{
		char point1[3],point2[3];
		char data[6];
		while(!fin.eof()){
			fin.getline(data,8,'\n');
			point1[0]=data[0];point1[1]=data[1];point1[2]='\0';
			point2[0]=data[3];point2[1]=data[4];point2[2]='\0';
			////
			nodes[to_int(point2)].hereIsYourNeighbor(to_int(point1));
			length++;
		}
	}
	fin.close();
	nodes[65].hereIsYourNeighbor(66);
	nodes[64].hereIsYourNeighbor(67);
	
}
int Node::getDistance(Node _node){
	int x=pos.x-_node.pos.x;
	int y=pos.y-_node.pos.y;
	return int(abs(x)+abs(y));
}
int Node::getDistance(Node *_node){
	int x=pos.x-_node->pos.x;
	int y=pos.y-_node->pos.y;
	return int(abs(x)+abs(y));
}
int Node::getDistance( Node _node1,Node _node2){
	int x=_node1.pos.x-_node2.pos.x;
	int y=_node1.pos.y-_node2.pos.y;
	return int(abs(x)+abs(y));
}
int Node::getDistance(sf::Vector2f _pos){
	int x=pos.x-_pos.x;
	int y=pos.y-_pos.y;
	return int(abs(x)+abs(y));
}
int Node::getDistance(int n){
	int x=pos.x-nodes[n].pos.x;
	int y=pos.y-nodes[n].pos.y;
	return int(abs(x)+abs(y));

}
Node** Node::getNeighbours(){
	/*
	_neighbours[0]=_neighbours[1]=_neighbours[2]=_neighbours[3]=NULL;
	_neighbours[0]=neighbor_right;
	_neighbours[1]=neighbor_left;
	_neighbours[2]=neighbor_up;
	_neighbours[3]=neighbor_down;
	*/
	/*
	if(neighbor_right!=NULL){
		_neighbours[0]=neighbor_right;
	}
	if(neighbor_left!=NULL){
		_neighbours[1]=neighbor_left;
	}
	if(neighbor_up!=NULL){
		_neighbours[2]=neighbor_up;
	}
	if(neighbor_down!=NULL){
		_neighbours[3]=neighbor_down;
	}
	*/
	return _neighbours;
}
int* Node::getNeighboursId(){
	/*
	neighbours_id[0]=neighbours_id[1]=neighbours_id[2]=neighbours_id[3]=-1;
	if(neighbor_right!=NULL){
		neighbours_id[0]=neighbor_right->id;
	}
	if(neighbor_left!=NULL){
		neighbours_id[1]=neighbor_left->id;
	}
	if(neighbor_up!=NULL){
		neighbours_id[2]=neighbor_up->id;
	}
	if(neighbor_down!=NULL){
		neighbours_id[3]=neighbor_down->id;
	}
	*/
	return neighbours_id;
}
char Node::getDirectionOf(Node *_node){
	if(neighbor_up==_node){
		return UP;
	}
	else if(neighbor_down==_node){
		return DOWN;
	}
	else if(neighbor_left==_node){
		return LEFT;
	}
	else if(neighbor_right==_node){	
		return RIGHT;
	}
	else{
		return NO;
	}
}
Node::Node(sf::Vector2f _pos){
	set(_pos);
	getNearestNeighbourDifferentNode();
}
void Node::addExtraPoints(){
	//ACTUAL_NODES;
}


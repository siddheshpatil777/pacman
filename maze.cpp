#include "maze.h"
sf::RenderWindow *Maze::window;
sf::RenderTexture Maze::maze_texture;
sf::Texture Maze::main_texture;
sf::Sprite Maze::sprite;
Maze::Maze(){
	
}
Maze::Maze(int h,int w,int r,int c){
	height=h;
	width=w;
	rows=r;
	cols=c;
//	new_window=new sf::RenderWindow (sf::VideoMode(800, 600), "temp window");
//	window.setActive(false);
//    window.setFramerateLimit(30);
//    window.clear(sf::Color::Black);
	//maze_data=new int*[36];
	//for(int i=0;i<28;i++){
	//	maze_data[i]=new int[36];
	//}
	
}
void Maze::setMazeData(char _pathForMazetemplate[]){
	strcpy(pathForMazetemplate,_pathForMazetemplate);
	if(!image.loadFromFile(_pathForMazetemplate)){
		cout<<"failed to load image for maze_template"<<"\n";
	}
	else{
		cout<<"succesfully  loaded image for maze_template"<<"\n";
	}
//	sf::Sprite sprite;
//	sprite.setTexture(image);
//	sprite.setScale(sf::Vector2f(10.0,10.0));
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			maze_data[i][j]=Tile::getTileCodeByColor(image.getPixel(j,i));
		}	
	}
	cout<<"WORLD_DATA CREATED"<<"\n";
}
void Maze::updateMaze(){
	//maze_texture.clear(sf::Color::Red);
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
		//	sf::IntRect area(j*TILE_SIZE,i*TILE_SIZE,TILE_SIZE,TILE_SIZE);
		//	main_texture.update(Tile::getTextureByCode(world_data[i][j]),j*TILE_SIZE,i*TILE_SIZE);
			Tile::drawAt(sf::Vector2f(j*TILE_SIZE,i*TILE_SIZE),maze_data[i][j]);
		}	
	}
	
	maze_texture.display();
	main_texture=maze_texture.getTexture();
	//main_texture.generateMipmap();
	sprite.setTexture(main_texture);
//	sprite.setScale(sf::Vector2f(0.25,0.25));
	/*
	sf::Image sav;
	sav=maze_texture.getTexture().copyToImage();
	if(!sav.saveToFile("temp/1.png")){
		cout<<"could not save image"<<"\n";
	}
	else{
		cout<<"saved image SUCCESFULLY "<<"\n";
	}
	*/
	
}
void Maze::drawMaze(){
	window->draw(sprite);
	//Sleep(20000);
    //window->display();
}
void Maze::loadAllTiles(){	
	sf::Color top_double_wall(255,0,10);
	sf::Color left_double_wall(14,209,69);
	sf::Color bottom_double_wall(184,61,186);
	sf::Color right_double_wall(255,196,0);
	//SINGLE WALLS
	/*
	sf::Color top_single_wall(224,47,47);
	sf::Color left_single_wall(18,129,18);
	sf::Color bottom_single_wall(124,6,126);
	sf::Color right_single_wall(255,127,39);
	*/
	sf::Color top_single_wall(124,6,126);
	sf::Color left_single_wall(255,127,39);
	sf::Color bottom_single_wall(224,47,47);
	sf::Color right_single_wall(18,129,18);
	//CURVES
	sf::Color top_left_curve(255,97,134);
	sf::Color bottom_left_curve(94,99,164);
	sf::Color bottom_right_curve(97,17,33);
	sf::Color top_right_curve(183,48,97);
	/*
	sf::Color top_left_curve(97,17,33);
	sf::Color bottom_left_curve(183,48,97);
	sf::Color bottom_right_curve(255,97,134);
	sf::Color top_right_curve(94,99,164);
	*/
	//corner
	sf::Color top_left_corner(196,255,14);
	sf::Color bottom_left_corner(83,16,16);
	sf::Color bottom_right_corner(185,122,86);
	sf::Color top_right_corner(63,72,204);
	// Ghost corner
	sf::Color top_left_ghost_wall(163,13,243);
	sf::Color bottom_left_ghost_wall(137,35,191);
	sf::Color bottom_right_ghost_wall(125,12,185);
	sf::Color top_right_ghost_wall(134,8,201);
	
	//
	sf::Color path(96,96,96);
	sf::Color blank(0,0,0);
	//
	sf::Color top_left_special_corner(140,255,251);
	sf::Color top_right_special_corner(177,34,112);
	sf::Color bottom_left_special_corner(9,19,161);
	sf::Color bottom_right_special_corner(226,35,93);
	//
	sf::Color top_left_big_corner(253,4,84);
	sf::Color top_right_big_corner(255,1,213);
	sf::Color bottom_left_big_corner(105,194,234);
	sf::Color bottom_right_big_corner(159,72,23);
	//
	sf::Color top_right_special_corner_flipped(255,222,109);
	sf::Color top_left_special_corner_flipped(229,138,156);
	//
	Tile::addTile(top_right_special_corner_flipped,"top_right_special_corner_flipped");
	Tile::addTile(top_left_special_corner_flipped,"top_left_special_corner_flipped");
	//
	Tile::addTile(blank,"blank");
	//
	Tile::addTile(top_double_wall,"top_double_wall");
	Tile::addTile(left_double_wall,"left_double_wall");
	Tile::addTile(bottom_double_wall,"bottom_double_wall");
	Tile::addTile(right_double_wall,"right_double_wall");
	//
	Tile::addTile(top_single_wall,"top_single_wall");
	Tile::addTile(left_single_wall,"left_single_wall");
	Tile::addTile(bottom_single_wall,"bottom_single_wall");
	Tile::addTile(right_single_wall,"right_single_wall");
	//
	Tile::addTile(top_left_ghost_wall,"top_left_ghost_wall");
	Tile::addTile(bottom_left_ghost_wall,"bottom_left_ghost_wall");
	Tile::addTile(bottom_right_ghost_wall,"bottom_right_ghost_wall");
	Tile::addTile(top_right_ghost_wall,"top_right_ghost_wall");
	//
	Tile::addTile(top_left_curve,"top_left_curve");
	Tile::addTile(bottom_left_curve,"bottom_left_curve");
	Tile::addTile(bottom_right_curve,"bottom_right_curve");
	Tile::addTile(top_right_curve,"top_right_curve");
	//
	Tile::addTile(top_left_corner,"top_left_corner");
	Tile::addTile(bottom_left_corner,"bottom_left_corner");
	Tile::addTile(bottom_right_corner,"bottom_right_corner");
	Tile::addTile(top_right_corner,"top_right_corner");
	//
	Tile::addTile(top_left_special_corner,"top_left_special_corner");
	Tile::addTile(bottom_left_special_corner,"bottom_left_special_corner");
	Tile::addTile(bottom_right_special_corner,"bottom_right_special_corner");
	Tile::addTile(top_right_special_corner,"top_right_special_corner");
	//
	Tile::addTile(top_left_big_corner,"top_left_big_corner");
	Tile::addTile(bottom_left_big_corner,"bottom_left_big_corner");
	Tile::addTile(bottom_right_big_corner,"bottom_right_big_corner");
	Tile::addTile(top_right_big_corner,"top_right_big_corner");
	//
	Tile::addTile(path,"path");
	
}
void Maze::setupEverythingForMaze(sf::RenderWindow* _window,char pathForTiles[]){
	sprite.setPosition(sf::Vector2f(0.0,0.0));
	window=_window;
	cout<<"Evrything Set Up FOr MAze"<<"\n";
	char path[70];
	strcpy(path,"images/main_tiles/");
//	strcat(path,pathForTiles);
	Tile::setupEveryThingForTile(window,&maze_texture,path);
	loadAllTiles();
	if(!maze_texture.create(448,576)){
		cout<<"ERRROR while creating maze texture"<<"\n";
	}
}
void Maze::destroyEverythingForMaze(){
	
	Tile::destroyEveryThingForTile();
	cout<<"Evrything destroyed Up FOr MAze"<<"\n";
}
Maze::~Maze(){
//	delete new_window;
	//for(int i=0;i<28;i++){
	//	delete [ ] maze_data[i];
	//}
	//delete maze_data;
}
void Maze::printMazeDataCode(){
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<maze_data[i][j]<<"  ";
		}	cout<<"\n";
	}
}
void Maze::set(int h,int w,int r,int c){
	height=h;
	width=w;
	rows=r;
	cols=c;
}
int Maze::getMazeDataByTileCoord(int i,int j){
	if(j<0||i<0||i>rows||j>cols){
		return -1;
	}
	return maze_data[i][j];
}
sf::Texture* Maze::getPointerToMazeTexture(){
	return &main_texture;
}
void Maze::findPoints(){
	sf::Color path(96,96,96);
	int code=Tile::getTileCodeByColor(path);
	for(int i=0;i<28;i++){
		for(int j=0;j<36;j++){
			if(code==getMazeDataByTileCoord(j,i)){
				bool exist=false;
			int q=0;
			//cout<<temp_maze.getMazeDataByTileCoord(i+1,j)<<" ";
			if(code==getMazeDataByTileCoord(j,i+1)&&code==getMazeDataByTileCoord(j-1,i)){
				q++;exist=true;
			}
			if(code==getMazeDataByTileCoord(j-1,i)&&code==getMazeDataByTileCoord(j,i-1)){
				q++;exist=true;
			}
			if(code==getMazeDataByTileCoord(j+1,i)&&code==getMazeDataByTileCoord(j,i+1)){
				q++;exist=true;
			}
			if(code==getMazeDataByTileCoord(j,i-1)&&code==getMazeDataByTileCoord(j+1,i)){
				q++;exist=true;
			}
			//if(||code==temp_maze.getMazeDataByTileCoord(i-1,j)||code==temp_maze.getMazeDataByTileCoord(i,j-1)||code==temp_maze.getMazeDataByTileCoord(i,j+1)){
			//	exist=true;
			//}
			if(exist){
				Node::addPointByTileCoord(i,j);
				//cout<<"Node ADDED i:"<<i<<" "<<"j:"<<j<<"\n";
			}
			}
		//	cout<<"q :"<<q<<"\n";
		}
	//	cout<<"\n";
	}	
	//	cout<<"1, 4 :"<<temp_maze.getMazeDataByTileCoord(4,1)<<" \n";
	//	cout<<"1, 3 :"<<temp_maze.getMazeDataByTileCoord(3,1)<<" ";
	Node::addPointByTileCoord(0,17);
	Node::addPointByTileCoord(27,17);
	Node::addPointByTileCoord(30,17);
	Node::addPointByTileCoord(-3,17);
//	Node::addExtraPoints();
	cout<<"FOUND nodes SUCCESFULLY "<<"\n";
}
void Maze::findPaths(){
	//
	for(int i=0;i<Node::nodes_length;i++){
		Path::addPathFromPointsIndex(i,Node::nodes[i].getSimilarPointWithLeastDistance('u'));
		cout<<"new starting Node"<<"\n";
		//int as=Node::nodes[i].getSimilarPointWithLeastDistance('u');
		//Path::addPathFromPointsIndex(0,i);
		//Path::addPathFromPointsIndex(i,);
		//Path::addPathFromPointsIndex(i,);
		//Path::addPathFromPointsIndex(i,);
		
	}
}



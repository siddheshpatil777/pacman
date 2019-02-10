#include "game.h"

Game::Game(sf::RenderWindow *win,World *wor){
	cout<<"GAME STARTED "<<"\n";
	
	window=win;
	world=wor;
	window->clear(sf::Color::Black);
	world->loadAllSprites("images/sprites/all_sprites.png");

	Pacman::setupEverythingForPacman();
	Ghost::setupEverythingForGhost();
	Hitbox::setupEverythingForHitboxes(window,10);
	Eatable::setupEverythingForEatable(window,world);
	//
	Eatable::loadAllEatablesFromFile("images/sprites/");
	Eatable::loadAllEatables("images/world/eatables_template.png");
	Eatable::setupAllEatables();
	Eatable::updateAllEatables();
	Pacman::addPacman(window,world);
	Ghost::addGhost(BLINKY,window,world);
	Ghost::setupAllGhosts();
//	Ghost::addGhost(PINKY,window,world);
	
	Pacman::loadAllSpritesFromFile();
	Ghost::loadAllSpritesFromFile();
	
	FPS=60;
	window->setActive(false);
	//window.setVerticalSyncEnabled(true);
//	AI::setupEverythingForAI();

	cout<<"printing p p p p p p"<<"\n";

}
Game::~Game(){

	Pacman::destroyEverythingForPacman();
	Ghost::destroyEverythingForGhost();
	Eatable::destroyEverythingForEatable();
	Hitbox::destroyEverythingForHitboxes();
	cout<<"GAME ENDED "<<"\n";	
}
void Game::gameLoop(){
	window->clear(sf::Color::Black);
	/*
	sf::Thread thread_hitbox;
	thread_hitbox=sf::Thread(&Hitbox::HandleHitboxes);
	thread_hitbox.launch();
*/
//	sf::Thread thread_hitbox(&Hitbox::HandleHitboxes);
	Hitbox::printAllHitboxData();
//	Network::startMainThread();
//	Text option1("1234567890",1,sf::Vector2i(10,10));
//	Array<Text> options(3);
//	options[0].set("start new game",1,sf::Vector2i(10,10));
//	options[1].set("check highscores",1,sf::Vector2i(10,12));
//	options[2].set("quit",1,sf::Vector2i(10,14));
//	Text option2("aaaa",0,sf::Vector2i(6,10));
	long int i=0;
	long int k=0;
	while (window->isOpen()){
        while (window->pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window->close();	
			}
        }
       
        //thread_hitbox.launch();
        Hitbox::HandleHitboxes();
		window->clear(sf::Color::Black);
		Pacman::respondToKeysAllPacmans();
		Ghost::respondToKeysAllGhosts();
		
		Pacman::moveAllPacmans();
		Ghost::moveAllGhosts();
	
		world->drawWorld();
		//Text::testAllCharacters();
// 		world->displayPoints();
		Eatable::drawAllEatables();
	//	Hitbox::drawAllHitboxes();
// 		world->displayPoints();
		Ghost::drawAllGhosts();
		Pacman::drawAllPacmans();
//		option1.draw();
//		option2.draw();
//		options[0].draw();
//		Text::drawTextToScreen("QWERTYUIOP",sf::Vector2i(6,10),0);
//Text::testAllCharacters();
		window->display();
//		Network::display();
		Eatable::updateAllEatables();
		Pacman::checkCollsionsForAllPacmans();
		Eatable::checkCollsionsForAllEatables();
//		Network::sendMainPacketToEveryone();
//		Network::display();
		//Hitbox::HandleHitboxes();
		//window->display();
    }
  //  thread_hitbox.terminate();
}
void Game::startScreen(){
	int selected_1,selected_2,selected_3,selected_color=2;
	selected_1=selected_color;
	selected_2=selected_3=0;
//	"Start New Game","check Highscores","check Highscores"
//	Array<Text> options(3);
//	options.push(Text("start new game",1,sf::Vector2i(10,10)));
//	options.push(Text("check highscores",1,sf::Vector2i(10,12)));
//	options.push(Text("quit",1,sf::Vector2i(10,14)));
	Text options[3];
	options[0].set("start new game",1,sf::Vector2i(10,10));
	options[1].set("check highscores",1,sf::Vector2i(10,12));
	options[2].set("quit",1,sf::Vector2i(10,14));
//	options.push("Start New Game");
//	options.push("check Highscores");
//	options.push("check Highscores");
	
//	while(true){
		options[0].draw();
		window->display();
			Sleep(1000000);
//		Text::displayText(,sf::Vector2i(10,10),selected_1,sf::Vector2f(1.0,1.0));
//		Text::displayText(,sf::Vector2i(10,12),selected_2,sf::Vector2f(1.0,1.0));
//		Text::displayText(,sf::Vector2i(10,14),selected_3,sf::Vector2f(1.0,1.0));
////		selected_1=selected_2=selected_3=0;
//		if(sf::Keyboard::isKeyPressed(sf::Keyboard::UP)){
//			selected_1=selected_2=selected_3=0;
//			
		
//	}
//	Text option1("Start New Game",1,sf::Vector2i(10,10));
//	option1.draw();

	
	
	
	
}	


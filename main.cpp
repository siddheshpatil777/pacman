#include "SFML/Graphics.hpp"
#include "game.h"
#include "network.h"
int main(){
//	Network::setupEverythingForNetwork();
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "My window");
    window.setActive(false);
    window.setFramerateLimit(30);
    window.clear(sf::Color::Black);
    World world(windowHeight,windowWidth,blockSize,&window);
	Game game(&window,&world);
	//Sleep(100000);
//	game.startScreen();
	game.gameLoop();
//	quitting;
    // run the program as long as the window is open
   //monash university
    return 0;
}



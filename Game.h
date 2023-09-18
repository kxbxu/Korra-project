#pragma once


#include <map>
#include "Player.h"


class Game
{
private:

	//Window
	sf::RenderWindow* window; 

	//Resources
	std::map<std::string,sf::Texture*> textures;

	//Player
	Player* player;	 

	//Private functions
	void initwindow();
	void initTexture();

	void initPlayer();

public:
	//constructor and destructor
	Game(); 
	virtual ~Game();

	//functions

	void run();

	void updatePollEvents();
	void updateInput();
	void update();
	void render();
};


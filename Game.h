#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <ctime>


class Game
{
private:
	sf::VideoMode videomode;
	sf::RenderWindow* window; 

	bool endGame;
	
	void initVariables();
	void initvindow();

	sf::Event sfmlEvent;	

public:
	//constructor and destructor
	Game();
	~Game();

	//functions

	const bool running() const;

	void pollEvents(); 

	void update();
	void render();
};


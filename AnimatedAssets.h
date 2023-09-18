#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <ctime>
#include <random>
#include <iostream>
#include <vector>

class AnimatedAssets: public sf::Sprite 
{
public:
	AnimatedAssets();		//starting position || veliocity  x->width  y->height
	virtual ~AnimatedAssets();

	void update();
	//virtual void render(sf::RenderWindow& target)=0

protected:
	sf::RenderWindow window_ch;                          //12-16 line _ch->character   _p for projectiles   
	sf::Texture texture_ch;
	sf::Sprite sprite_ch;
	sf::Vector2f position_ch;                            //containers for position and veliocity
	sf::Vector2f velocity_ch;

	float movementSpeed;


	//virtual void handleColission() = 0;								//colission handling *in process*
};


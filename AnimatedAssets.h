#ifndef ANIMOWANEASSETY_H
#define ANIMOWANEASSETY_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <ctime>
#include <random>
#include <iostream>
#include <vector>
#include <memory>
#include <time.h>

#include "ProjectileType.h"

class AnimatedAssets: public sf::Sprite 
{
public:
	AnimatedAssets();		
	virtual ~AnimatedAssets();


	//Acessors
	const sf::Vector2f& getPos();

protected:
	sf::RenderWindow window_ch;                          //12-16 line _ch->character   _p for projectiles   
	sf::Texture texture_ch;
	sf::Sprite sprite_ch;
	sf::Vector2f position_ch;                            //containers for position and veliocity
	sf::Vector2f velocity_ch;

	float movementSpeed;
	float movementSpeedmemory;


	//virtual void handleColission() = 0;								//colission handling *in process*
};

#endif // !ANIMOWANEASSETY_H
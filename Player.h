#pragma once

#include <SFML/Graphics.hpp>
#include "AnimatedAssets.h"

class Player: public AnimatedAssets
{
private:
	void initTexture();
	void initSprite();
	std::vector<sf::IntRect> Up;
	std::vector<sf::IntRect> Down;
	std::vector<sf::IntRect> Right;
	std::vector<sf::IntRect> Left;
	float time_per_frame;
	float elapsed_time;
	sf::Clock clock;
	int actual_Frame;
	Sprite sprite;


public:
	Player();
	void render(sf::RenderWindow& target);
	void animationUp();
	void animationDown();
	void animationRight();
	void animationLeft();
	void move(const float directionX, const float directionY, const float deltaTime);
	//void render(sf::RenderWindow& target);
};


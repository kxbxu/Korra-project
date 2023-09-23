#include "AnimatedAssets.h"

AnimatedAssets::AnimatedAssets()
{
	this->movementSpeed = 0;
	this->movementSpeedmemory = 0;
}

AnimatedAssets::~AnimatedAssets()
{

}

const sf::Vector2f& AnimatedAssets::getPos()
{
	return this->sprite_ch.getPosition();
}




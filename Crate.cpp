#include "Crate.h"

Crate::Crate()
{

}

Crate::Crate(float x, float y)
{
	this->initTexture();
	this->initSprite();
	this->sprite_ch.setPosition(sf::Vector2f(x, y));
	this->sprite_ch.setScale(0.25, 0.25);
}

void Crate::initTexture()
{
	this->texture_ch.loadFromFile("crate.png");
}

void Crate::initSprite()
{
	this->sprite_ch.setTexture(this->texture_ch);
}

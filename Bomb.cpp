#include "Bomb.h"

void Bomb::initTexture()
{
	this->texture_ch.loadFromFile("bomb.png");
}

void Bomb::initSprite()
{
	this->sprite_ch.setTexture(this->texture_ch);
}

Bomb::Bomb()
{

}

Bomb::Bomb(float x, float y)
{

	this->initTexture();
	this->initSprite();
	this->sprite_ch.setPosition(sf::Vector2f(x, y));
	this->sprite_ch.setScale(0.15, 0.15);
}

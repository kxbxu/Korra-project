#include "Heart.h"

void Heart::initTexture()
{
	this->texture_ch.loadFromFile("heart.png");
}

void Heart::initSprite()
{
	this->sprite_ch.setTexture(this->texture_ch);
}

Heart::Heart()
{

}

Heart::Heart(float x, float y)
{
	this->initTexture();
	this->initSprite();
	this->sprite_ch.setPosition(sf::Vector2f(x, y));
	this->sprite_ch.setScale(0.35, 0.35);
}

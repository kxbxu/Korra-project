#include "Projectiles.h"

Projectiles::Projectiles()
{

}

Projectiles::Projectiles(sf::Texture& texture, float dirX, float dirY, float movement_speed)
{
	this->shape.setTexture(texture);
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->movementspeed = movement_speed;

}

Projectiles::~Projectiles()
{
}

void Projectiles::update()
{
	this->shape.move(this->movementspeed * this->direction);
}

void Projectiles::render(sf::RenderWindow* target)
{
	target->draw(this->shape);
}

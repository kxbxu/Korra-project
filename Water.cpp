#include "Water.h"

Water::Water(sf::Texture* texture, float posX, float posY, float dirX, float dirY)
	:Projectiles(texture,posX,posY,dirX,dirY)
{
	shape.setScale(0.45f, 0.45f);
	this->movementspeed = 500.f;
	this->dmg = 35;
}

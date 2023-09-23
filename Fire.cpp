#include "Fire.h"

Fire::Fire(sf::Texture* texture, float posX, float posY, float dirX, float dirY)
	:Projectiles(texture,posX,posY,dirX,dirY)
{
	this->movementspeed = 382.f;   //7
	this->dmg = 50;
}

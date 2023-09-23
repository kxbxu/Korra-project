#include "Earth.h"

Earth::Earth(sf::Texture* texture, float posX, float posY, float dirX, float dirY)
	:Projectiles(texture,posX,posY,dirX,dirY)
{
	this->movementspeed = 250.f;
	this->dmg = 2;
}

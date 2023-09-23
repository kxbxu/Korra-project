#include "Air.h"

Air::Air(sf::Texture* texture, float posX, float posY, float dirX, float dirY)
	:Projectiles(texture,posX,posY, dirX,  dirY)
{
	this->movementspeed = 500.f;
	this->dmg = 4;
}

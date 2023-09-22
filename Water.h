#ifndef Water_H
#define Water_H

#include "Projectiles.h"

class Water: public Projectiles
{
public:
	Water(sf::Texture* texture, float posX, float posY, float dirX, float dirY);
	
};

#endif // !Water_H
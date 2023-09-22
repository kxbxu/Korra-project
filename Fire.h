#ifndef Fire_H
#define Fire_H

#include "Projectiles.h"

class Fire: public Projectiles
{
public:
	Fire(sf::Texture* texture, float posX, float posY, float dirX, float dirY);
};

#endif // !Fire_H
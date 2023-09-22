#ifndef Earth_H
#define Earth_H

#include "Projectiles.h"


class Earth: public Projectiles
{
public:
	Earth(sf::Texture* texture, float posX, float posY, float dirX, float dirY);
};

#endif //  !Earth_H
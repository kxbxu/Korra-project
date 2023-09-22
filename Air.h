#ifndef Air_H
#define Air_H

#include "Projectiles.h"

class Air :public Projectiles
{
public:
	Air(sf::Texture* texture, float posX, float posY, float dirX, float dirY);
};

#endif  //  !Air_H
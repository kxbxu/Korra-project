#ifndef BOMB_H
#define HEARTH_H

#include "Loot.h"

class Bomb : public Loot
{
private:
	void initTexture();
	void initSprite();
public:
	Bomb();
	Bomb(float x, float y);
};


#endif // !BOMB_H
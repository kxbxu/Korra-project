#ifndef CRATE_H
#define CRATE_H

#include "Loot.h"

class Crate: public Loot
{
public:
	Crate();
	Crate(float x, float y);


private:
	void initTexture();
	void initSprite();
};

#endif // !CRATE_H






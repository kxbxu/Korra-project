#ifndef HEART_H
#define HEART_H

#include "Loot.h"

class Heart: public Loot
{
private:
	void initTexture();
	void initSprite();
public:
	Heart();
	Heart(float x, float y);
};


#endif // !HEART_H





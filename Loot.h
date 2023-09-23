#ifndef LOOT_H
#define LOOT_H

#include "AnimatedAssets.h"

class Loot: public AnimatedAssets
{
public:
	Loot();
	Loot(float x, float y);

	void render(sf::RenderWindow* target);

	//accessor
	const sf::FloatRect getBounds() const;
};

#endif // !LOOT_H
#include "Loot.h"

Loot::Loot()
{

}

Loot::Loot(float x, float y)
{
	this->sprite_ch.setPosition(sf::Vector2f(x, y));
}

void Loot::render(sf::RenderWindow* target)
{
	target->draw(this->sprite_ch);
}

const sf::FloatRect Loot::getBounds() const
{
	return this->sprite_ch.getGlobalBounds();
}

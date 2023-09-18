#ifndef Projectiles_H
#define Projetiles_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>


class Projectiles
{
private:
	sf::Sprite shape;
	sf::Vector2f direction;
	float movementspeed;
public:
	Projectiles();
	Projectiles(sf::Texture& texture,float dirX, float dirY,float movement_speed );
	virtual ~Projectiles();

	void update();
	void render(sf::RenderWindow* target);
};

#endif // !Projectiles_H 
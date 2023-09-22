#ifndef Projectiles_H
#define Projectiles_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cmath>
#include "ProjectileType.h"



class Projectiles
{
protected:
	sf::Sprite shape;
	sf::Vector2f direction;
	sf::Vector2f speeddirection;
	float movementspeed;
	float dmg;
	
public:
	Projectiles();
	Projectiles(sf::Texture* texture,float posX,float posY,float dirX, float dirY );
	virtual ~Projectiles();

	bool is_reloaded(float elapsed);


	//accessor
	const sf::FloatRect getBounds() const;
	const float getDamage() const;

	void update(float deltaTime);
	void speedDirection();
	void render(sf::RenderWindow* target);
	
};

#endif // !Projectiles_H 
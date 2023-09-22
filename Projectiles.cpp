#include "Projectiles.h"

Projectiles::Projectiles()
{
	//std::cout << "hi";
}

Projectiles::Projectiles(sf::Texture* texture, float posX, float posY, float dirX, float dirY)
	:movementspeed(0.0)
{

	this->shape.setTexture(*texture);

	this->shape.setPosition(posX, posY);
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->speedDirection();
	
	
}

Projectiles::~Projectiles()
{
}


const sf::FloatRect Projectiles::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const float Projectiles::getDamage() const
{
	return this->dmg;
}


void Projectiles::update(float deltaTime)
{
	this->shape.move(this->movementspeed*deltaTime * this->speeddirection);
}

void Projectiles::speedDirection()
{
	if (this->direction.x - this->shape.getPosition().x == 0 && this->direction.y - this->shape.getPosition().y != 0) {
		this->speeddirection.x = 0.f;
		this->speeddirection.y = (this->direction.y - this->shape.getPosition().y) / (abs(this->direction.y - this->shape.getPosition().y));
	}
	else if (this->direction.y - this->shape.getPosition().y == 0 && this->direction.x - this->shape.getPosition().x != 0) {
		this->speeddirection.y = 0.f;
		this->speeddirection.x = (this->direction.x - this->shape.getPosition().x) / (abs(this->direction.x - this->shape.getPosition().x));
	}
	//else if (this->direction.y - this->shape.getPosition().y == 0 && this->direction.x - this->shape.getPosition().x == 0) {}  this case can be excluded in the updateInput method ->game.cpp
	else {
		this->speeddirection.x=std::cos(std::atan((this->direction.y - this->shape.getPosition().y)/(this->direction.x - this->shape.getPosition().x)))* (this->direction.x - this->shape.getPosition().x) / (abs(this->direction.x - this->shape.getPosition().x));
		this->speeddirection.y = std::sin(std::atan((this->direction.y - this->shape.getPosition().y) / (this->direction.x - this->shape.getPosition().x))) * (this->direction.x - this->shape.getPosition().x) / (abs(this->direction.x - this->shape.getPosition().x));
		// for x cos(arctan(delta_x/delta_y))*delta_x/|delta_x|      
		// for y sin(arctan(delta_x/delta_y))*delta_x/|delta_x| 
	}
}

void Projectiles::render(sf::RenderWindow* target)
{
	target->draw(this->shape);
}

#include "CommonEnemy.h"

void CommonEnemy::initVariables()
{
	this->movementSpeed = 100.f;
	this->hpMax = 70;
	this->hp = 70;
	this->dmg = 20;
	this->point = 5;

	this->isburn = false;
	this->isslowness = false;
	this->isknockback = false;

	this->burn_elapsed = 0;
	this->slowness_elapsed = 0;
}

void CommonEnemy::speedDirection(float x, float y)
{
	if (changeDirection) {

		this->direction.x = x;
		this->direction.y = y;

		if (this->direction.x - this->sprite_ch.getPosition().x == 0 && this->direction.y - this->sprite_ch.getPosition().y != 0) {
			this->speeddirection.x = 0.f;
			this->speeddirection.y = (this->direction.y - this->sprite_ch.getPosition().y) / (abs(this->direction.y - this->sprite_ch.getPosition().y));
		}
		else if (this->direction.y - this->sprite_ch.getPosition().y == 0 && this->direction.x - this->sprite_ch.getPosition().x != 0) {
			this->speeddirection.y = 0.f;
			this->speeddirection.x = (this->direction.x - this->sprite_ch.getPosition().x) / (abs(this->direction.x - this->sprite_ch.getPosition().x));
		}
		else if (this->direction.y - this->sprite_ch.getPosition().y == 0 && this->direction.x - this->sprite_ch.getPosition().x == 0) {
			this->speeddirection.x = 0.f;
			this->speeddirection.y = 0.f;

		}
		else {
			this->speeddirection.x = std::cos(std::atan((this->direction.y - this->sprite_ch.getPosition().y) / (this->direction.x - this->sprite_ch.getPosition().x))) * (this->direction.x - this->sprite_ch.getPosition().x) / (abs(this->direction.x - this->sprite_ch.getPosition().x));
			this->speeddirection.y = std::sin(std::atan((this->direction.y - this->sprite_ch.getPosition().y) / (this->direction.x - this->sprite_ch.getPosition().x))) * (this->direction.x - this->sprite_ch.getPosition().x) / (abs(this->direction.x - this->sprite_ch.getPosition().x));
			// for x cos(arctan(delta_x/delta_y))*delta_x/|delta_x|      
			// for y sin(arctan(delta_x/delta_y))*delta_x/|delta_x| 
		}
		changeDirection = true;
	}
}

CommonEnemy::CommonEnemy(sf::Texture* texture, float pos_x, float pos_y,float dirX,float dirY)
	:Enemy(texture,pos_x,pos_y,dirX,dirY)
{
	this->initVariables();
	this->sprite_ch.setScale(0.8f, 0.8f);
	this->speedDirection(dirX, dirY);
}

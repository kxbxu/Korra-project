#include "Enemy.h"


void Enemy::initShapes()
{
}

Enemy::Enemy(sf::Texture* texture,float pos_x, float pos_y,float dirX,float dirY)
{
    this->sprite_ch.setTexture(*texture);
    this->sprite_ch.setPosition(pos_x, pos_y);
    this->initShapes();
    this->changeDirection = true;
    this->direction.x = dirX;
    this->direction.y = dirY;
    
}

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
}


//functions
void Enemy::update(float deltaTime,float dirX,float dirY)
{
    //targeting the player and going into his direction
    this->speedDirection(dirX,dirY);
    this->sprite_ch.move(this->movementSpeed * deltaTime*this->speeddirection);

    //checking effects

    if (this->isburn) {
        this->burn(deltaTime);
    }
    if (this->isknockback) {
        this->knockback(deltaTime);
    }
    if (this->isslowness) {
        this->slowness(deltaTime);
    }

}

void Enemy::render(sf::RenderWindow* target)
{
    target->draw(this->sprite_ch);
}

void Enemy::LoseHp(float dmg)
{
    this->hp -= dmg;
}

void Enemy::burn(float deltaTime)
{
    if (burn_elapsed >= 3) {
        burn_elapsed = 0;
        isburn = false;
        period = 0;
        isred = false;
        this->sprite_ch.setColor(sf::Color::White);
    }
    else {
        burn_elapsed += deltaTime;

        if (burn_elapsed >= 0.5 + this->period * 0.5) {
            ++period;
            if (this->isred) {
                this->sprite_ch.setColor(sf::Color::White);
            }
            else {
                this->sprite_ch.setColor(sf::Color::Red);
            }
            isred = !isred;
            hp -= hpMax * 0.035f;
        }
    }

}

void Enemy::slowness(float deltaTime)
{
}

const sf::FloatRect Enemy::getBounds() const
{
    return this->sprite_ch.getGlobalBounds();
}

void Enemy::knockback(float deltaTime)
{
    this->sprite_ch.move(this->movementSpeed * (-1) * this->speeddirection);
    isknockback = false;
}

void Enemy::is_burn()
{
    isburn = true;
}

void Enemy::is_slowness()
{
    isslowness = true;
}

void Enemy::is_knockback()
{
    isknockback = true;
}

bool Enemy::isAlive()
{
    return this->hp > 0;
}

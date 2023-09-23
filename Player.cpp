#include "Player.h"


Player::Player(float X, float Y)
    : AnimatedAssets() {
    this->initTexture();
    this->initSprite();
    this->initVariables();
    this->sprite_ch.setPosition(X, Y);
}

void Player::animationDown()
{
    frame_time += elapsed_time;
    if (time_per_frame < frame_time) {
        actual_Frame++;
        frame_time = 0;
        if (actual_Frame == Down.size()) {
            actual_Frame = 0;
        }
        //std::cout << actual_Frame<<std::endl;  //w celu sprawdzenia dzialnia kodu
        sprite_ch.setTextureRect(Down[actual_Frame]);
    }
}

void Player::animationUp()
{
    frame_time += elapsed_time;
    if (time_per_frame < frame_time) {
        actual_Frame++;
        frame_time = 0;
        if (actual_Frame == Up.size()) {
            actual_Frame = 0;
        }
        sprite_ch.setTextureRect(Up[actual_Frame]);
    }
}

void Player::animationRight()
{
    frame_time += elapsed_time;
    if (time_per_frame < frame_time) {
        actual_Frame++;
        frame_time = 0;
        if (actual_Frame == Right.size()) {
            actual_Frame = 0;
        }
        sprite_ch.setTextureRect(Right[actual_Frame]);
    }
}

void Player::animationLeft()
{
    frame_time += elapsed_time;
    if (time_per_frame < frame_time) {
        actual_Frame++;
        frame_time = 0;
        if (actual_Frame == Left.size()) {
            actual_Frame = 0;
        }
        sprite_ch.setTextureRect(Left[actual_Frame]);
    }
}

void Player::isLoadedW()
{
    this->is_loadedW = false;
    insideElapsedW = 0;
}

void Player::isLoadedE()
{
    this->is_loadedE = false;
    insideElapsedE = 0;
}

void Player::isLoadedF()
{
    this->is_loadedF = false;
    insideElapsedF = 0;
}

void Player::isLoadedA()
{
    this->is_loadedA = false;
    insideElapsedA = 0;
}

void Player::LoseHp(float dmg)
{
    this->hp -= dmg;

    if (this->hp < 0) {
        this->hp = 0;
    }
   
}

void Player::addHp(float HP)
{
    this->hp += HP;
    if (this->hp >= this->maxHp) {
        this->hp = this->maxHp;
    }
}

const sf::FloatRect Player::getBounds() const
{
    return this->sprite_ch.getGlobalBounds();
}

const float Player::getDamage() const
{
    return this->collisionDmg;
}

const float& Player::getHp() const
{
    return this->hp;
}

const float& Player::getHpMax() const
{
    return this->maxHp; 
}

bool Player::isAlive()
{
    return this->hp > 0;
}

bool Player::getWater()
{
    return is_loadedW;
}

bool Player::getEarth()
{
    return is_loadedE;
}

bool Player::getFire()
{
    return is_loadedF;
}

bool Player::getAir()
{
    return is_loadedA;
}

void Player::updateAttack()
{
    if (!is_loadedW) {
        if (insideElapsedW < cooldownW) {
            insideElapsedW += elapsed_time;
        }
        else {
            is_loadedW = true;
        }
    }
    
    if (!is_loadedE) {
        if (insideElapsedE < cooldownE) {
            insideElapsedE += elapsed_time;
        }
        else {
            is_loadedE = true;
        }
    }
    
    if (!is_loadedF) {
        if (insideElapsedF < cooldownF) {
            insideElapsedF += elapsed_time;
        }
        else {
            is_loadedF = true;
        }
    }
    
    if (!is_loadedA) {
        if (insideElapsedA < cooldownA) {
            insideElapsedA += elapsed_time;
        }
        else {
            is_loadedA = true;
        }
    }
    
}

void Player::update() 
{
    this->updateAttack();
}

void Player::move(const float directionX, const float directionY)
{
    this->sprite_ch.move(this->movementSpeed*directionX*elapsed_time,this->movementSpeed*directionY*elapsed_time);
}

void Player::timeChecking()
{
    elapsed_time = this->clock.getElapsedTime().asSeconds();
    this->clock.restart();
}

void Player::initTexture()
{
    if (!this->texture_ch.loadFromFile("player_t.png")) {
        std::cout << "ERROR->TEXTURE CANNOT BE LOADED ";
    }
}

void Player::initSprite()
{
    this->sprite_ch.setTexture(this->texture_ch);
    sprite_ch.setTextureRect(sf::IntRect(0, 0, 65, 80));
}

void Player::initVariables()
{
    this->movementSpeed = 300.f;                //5.5f;
    this->time_per_frame = 0.2f;
    actual_Frame = 0;
    Down.emplace_back(sf::IntRect(0, 0, 64, 80));
    Down.emplace_back(sf::IntRect(65, 0, 64, 80));
    Down.emplace_back(sf::IntRect(130, 0, 64, 80));
    Left.emplace_back(sf::IntRect(0, 80, 64, 80));
    Left.emplace_back(sf::IntRect(65, 80, 64, 80));
    Left.emplace_back(sf::IntRect(130, 80, 64, 80));
    Right.emplace_back(sf::IntRect(0, 160, 64, 80));
    Right.emplace_back(sf::IntRect(65, 160, 64, 80));
    Right.emplace_back(sf::IntRect(130, 160, 64, 80));
    Up.emplace_back(sf::IntRect(0, 240, 64, 80));
    Up.emplace_back(sf::IntRect(65, 240, 64, 80));
    Up.emplace_back(sf::IntRect(130, 240, 64, 80));

    //cooldowns
    cooldownF = 1.4f;              //fire
    insideElapsedF = 0.f;           
    is_loadedF = true;
    cooldownE = 3.f;                 //earth
    insideElapsedE = 0.f;
    is_loadedE = true;
    cooldownA = 5.f;                   //air
    insideElapsedA = 0.f;
    is_loadedA = true;
    cooldownW = 0.2f;                 //water
    insideElapsedW = 0.f;
    is_loadedW = true;
    //collision damage
    collisionDmg = 1.f;
    //
    maxHp = 300;
    hp = maxHp;
}

void Player::render(sf::RenderWindow& target) {
    
    target.draw(sprite_ch);
    
}
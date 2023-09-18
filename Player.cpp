#include "Player.h"


Player::Player()
    : AnimatedAssets() {
    this->initTexture();
    this->initSprite();
    sprite_ch.setTextureRect(sf::IntRect(0, 0, 65, 80));

    //setTextureRect(sf::IntRect(0, 0, 65, 80));
    //this->texture_ch.loadFromFile("player_t.png");
    //this->sprite_ch.setTexture(this->texture_ch);
    //this->sprite_ch.setTextureRect(sf::IntRect(0, 0, 65, 80));

    this->movementSpeed = 300000.f;
    this->time_per_frame = 0.3f;    
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
}

void Player::animationDown()
{
    elapsed_time = elapsed_time + clock.getElapsedTime().asSeconds();
    this->clock.restart();
    if (time_per_frame < elapsed_time) {
        actual_Frame++;
        elapsed_time = 0;
        if (actual_Frame == Down.size()) {
            actual_Frame = 0;
        }
        //std::cout << actual_Frame<<std::endl;  //w celu sprawdzenia dziania kodu
        sprite_ch.setTextureRect(Down[actual_Frame]);
    }
}

void Player::animationUp()
{
    elapsed_time = elapsed_time + clock.getElapsedTime().asSeconds();
    this->clock.restart();
    if (time_per_frame < elapsed_time) {
        actual_Frame++;
        elapsed_time = 0;
        if (actual_Frame == Up.size()) {
            actual_Frame = 0;
        }
        sprite_ch.setTextureRect(Up[actual_Frame]);
    }
}

void Player::animationRight()
{
    elapsed_time = elapsed_time + clock.getElapsedTime().asSeconds();
    this->clock.restart();
    if (time_per_frame < elapsed_time) {
        actual_Frame++;
        elapsed_time = 0;
        if (actual_Frame == Right.size()) {
            actual_Frame = 0;
        }
        sprite_ch.setTextureRect(Right[actual_Frame]);
    }
}

void Player::animationLeft()
{
    elapsed_time = elapsed_time + clock.getElapsedTime().asSeconds();
    this->clock.restart();
    if (time_per_frame < elapsed_time) {
        actual_Frame++;
        elapsed_time = 0;
        if (actual_Frame == Left.size()) {
            actual_Frame = 0;
        }
        sprite_ch.setTextureRect(Left[actual_Frame]);
    }
}

void Player::move(const float directionX, const float directionY,const float deltaTime)
{
    float distanceX = this->movementSpeed * directionX * deltaTime;
    float distanceY = this->movementSpeed * directionY * deltaTime;

    this->sprite_ch.move(distanceX, distanceY);
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
    
}

void Player::render(sf::RenderWindow& target) {
    
    target.draw(sprite_ch);
    
}
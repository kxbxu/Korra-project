#ifndef PLAYER_H
#define PLAYE_H

#include <SFML/Graphics.hpp>
#include "AnimatedAssets.h"

class Player: public AnimatedAssets
{
private:
	//animation
	std::vector<sf::IntRect> Up;
	std::vector<sf::IntRect> Down;
	std::vector<sf::IntRect> Right;
	std::vector<sf::IntRect> Left;
	float time_per_frame;
	float frame_time;
	float elapsed_time;
	sf::Clock clock;
	int actual_Frame;
	Sprite sprite;
	//attacks cooldown
	float cooldownF;
	float insideElapsedF;
	bool is_loadedF;
	float cooldownE;
	float insideElapsedE;
	bool is_loadedE;
	float cooldownA;
	float insideElapsedA;
	bool is_loadedA;
	float cooldownW;
	float insideElapsedW;
	bool is_loadedW;
	//collision damage
	float collisionDmg;
	//player hp
	float hp;
	float maxHp;

	//private functions
	void initTexture();
	void initSprite();
	void initVariables();

public:
	Player(float X,float Y);
	void render(sf::RenderWindow& target);
	void animationUp();
	void animationDown();
	void animationRight();
	void animationLeft();
	void isLoadedW();
	void isLoadedE();
	void isLoadedF();
	void isLoadedA();

	void LoseHp(float dmg);
	void addHp(float HP);

	//Accesor                        should be put in AnimatedAssets
	const sf::FloatRect getBounds() const;
	const float getDamage() const;
	const float& getHp() const;
	const float& getHpMax() const;

	//hp>0?         //also should be put in AnimatedAssets
	bool isAlive();
	
	bool getWater();
	bool getEarth();
	bool getFire();
	bool getAir();

	void updateAttack();
	void update();
	void move(const float directionX, const float directionY);
	void timeChecking();
};

#endif // !PLAYER_H
#ifndef ENEMY_H
#define ENEMY_H


#include "AnimatedAssets.h"

class Enemy :
    public AnimatedAssets
{
protected:
    int type;
    float hp;
    float hpMax;
    int dmg;
    int point;
    sf::Vector2f speeddirection;
    sf::Vector2f direction;
    int period = 0;

    //bool for activate efects function
    bool isburn;
    bool isslowness;
    bool isknockback;

    //burnstuff
    bool isred;

    //elapsed time of effects
    float burn_elapsed;
    float slowness_elapsed;
    
    bool changeDirection;

    virtual void initVariables()=0;
    virtual void speedDirection(float x,float y) = 0;
    void initShapes();

public:

    Enemy();
    Enemy(sf::Texture* texture,float pos_x,float pos_y,float dirX,float dirY);
    virtual ~Enemy();

    //functions
    void update(float deltaTime,float dirX,float dirY);
    void render(sf::RenderWindow* target);

    void LoseHp(float dmg);

    //efects function
    void burn(float deltaTime);
    void slowness(float deltaTime);
    void knockback(float deltaTime);

    //setting effects Boolean to true
    void is_burn();
    void is_slowness();
    void is_knockback();

    //hp>0?
    bool isAlive();

    //Accesor
    const sf::FloatRect getBounds() const;
    const int& getPoints() const;
    const float& getDmg() const;
    const float& getMaxHp() const;         //using to lose all hp after collision between player and speedster enemy /put here bcs it's seems to be usefull/



};

#endif  // !ENEMY_H

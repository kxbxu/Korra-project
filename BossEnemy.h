#ifndef BOSSENEMY_H
#define BOSSENEMY_H

#include "Enemy.h"
class BossEnemy :
    public Enemy
{
private:
    virtual void initVariables() override;
    virtual void speedDirection(float x, float y) override;

public:
    BossEnemy(sf::Texture* texture, float pos_x, float pos_y,float dirX,float dirY);
};


#endif // !BOSSENEMY_H



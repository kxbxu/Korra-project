#ifndef SPEEDSTERENEMY_H
#define SPEEDSTERENEMY_H

#include "Enemy.h"
class SpeedsterEnemy :
    public Enemy
{
private:
    virtual void initVariables() override;
    virtual void speedDirection(float x, float y) override;

public:
    SpeedsterEnemy(sf::Texture* texture, float pos_x, float pos_y,float dirX,float dirY);
};

#endif // !SPEEDSTERENEMY_H





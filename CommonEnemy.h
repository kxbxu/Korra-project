#ifndef COMMONENEMY_H
#define COMMONENEMY_H

#include "Enemy.h"


class CommonEnemy :
    public Enemy
{
private:
    virtual void initVariables() override;
    virtual void speedDirection(float x, float y) override;

public:
    CommonEnemy(sf::Texture* texture, float pos_x, float pos_y,float dirX,float dirY);
};

#endif // !COMMONENEMY_H






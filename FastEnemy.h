#ifndef FASTENEMY_H
#define FASTENEMY_H

#include "Enemy.h"
class FastEnemy :
    public Enemy
{
private:
    virtual void initVariables() override;
    virtual void speedDirection(float x, float y) override;
public:
    FastEnemy(sf::Texture* texture, float pos_x, float pos_y,float dirX,float dirY);
};

#endif // !FASTENEMY_H





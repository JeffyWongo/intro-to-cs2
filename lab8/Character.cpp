#include "Character.h"

Character::Character(HeroType type, 
const string &name, 
double health, 
double attackStrength)
 : type(type), 
name(name), 
health(health), 
attackStrength(attackStrength) 
{   }

HeroType Character::getType() const
{
    return type;
}

const string& Character::getName() const
{
    return name;
}

int Character::getHealth() const
{
    int inthealth = health;
    return inthealth;
}

void Character::damage(double d)
{
    health -= d;
}

bool Character::isAlive() const
{
    if(getHealth() > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
#include "character.h"
using namespace std;

Character::Character()
{
    _name = "none";
    _health = 0;
}

Character::Character(string name)
{
    _name = name;
    _health = 0;
}

Character::Character(double health)
{
    _name = "none";
    _health = health;
}

Character::Character(string name, double health)
{
    _name = name;
    _health = health;
}

string Character::getName() const
{
    return _name;
}

double Character::getHealth() const
{
    return _health;
}

double Character::setHealth(double health)
{
    _health = health;
}

void Character::damage(double health)
{
    _health -= health;
}

bool Character::isAlive()
{
    if(_health > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
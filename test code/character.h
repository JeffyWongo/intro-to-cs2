#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
using namespace std;

class Character
{
    private:
        string _name;
        double _health;
    public:
        Character();
        Character(string name);
        Character(double health);
        Character(string name, double health);
        string getName() const;
        double getHealth() const;
        double setHealth(double health);
        void damage(double health);
        bool isAlive();
};
#endif
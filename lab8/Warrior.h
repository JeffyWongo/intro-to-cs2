#ifndef __WARRIOR_H__
#define __WARRIOR_H__
#include <string>
#include <iostream>
#include "Character.h"
using namespace std;


class Warrior : public Character 
{
    private:
        string allegiance;

    public:
        Warrior(const string &name, 
                double health, 
                double attackStrength, 
                const string &allegiance);
        const string &getAllegiance() const;
        void attack(Character &opponent) override;

};
#endif
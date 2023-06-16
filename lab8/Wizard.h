#ifndef __WIZARD_H__
#define __WIZARD_H__
#include <string>
#include <iostream>
#include "Character.h"
using namespace std;

class Wizard : public Character
{
    private:
        int rank;

    public:
        Wizard(const string& name, 
                double health, 
                double attackStrength, 
                int rank);
        const int getRank() const;
        void attack(Character &opponent) override;
};
#endif
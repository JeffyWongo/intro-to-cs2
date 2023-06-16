#ifndef __ELF_H__
#define __ELF_H__
#include <string>
#include <iostream>
#include "Character.h"
using namespace std;

class Elf : public Character
{
    private:
        string family;
 
    public:
        Elf(const string& name, 
            double health, 
            double attackStrength, 
            const string& family);
        const string& getFamily() const;
        void attack(Character &opponent) override;
};
#endif
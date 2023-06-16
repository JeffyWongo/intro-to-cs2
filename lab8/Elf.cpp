#include "Elf.h"

Elf::Elf(const string &name, 
        double health, 
        double attackStrength, 
        const string &family)
 : Character(ELF, name, health, attackStrength), family(family) 
{  }

const string& Elf::getFamily() const
{
    return family;
}

void Elf::attack(Character &opponent)
{
    if(opponent.getType() == ELF)
    {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if(opp.getFamily() == family)
        {
            cout << "Elf " << getName() << " does not attack Elf " << opp.getName() << "." << endl;
            cout << "They are both members of the " << getFamily() << " family." << endl;
            return;
        }
    }
    cout << "Elf " << getName() << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
    double totalDamage;
    totalDamage = (health/MAX_HEALTH) * attackStrength;
    opponent.damage(totalDamage);
    cout << opponent.getName() << " takes " << totalDamage << " damage." << endl;
}
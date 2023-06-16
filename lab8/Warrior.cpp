#include "Warrior.h"


Warrior::Warrior(const string &name, 
                double health, 
                double attackStrength, 
                const string &allegiance)
 : Character(WARRIOR, name, health, attackStrength), allegiance(allegiance) 
 {  }

 const string& Warrior::getAllegiance() const
 {
    return allegiance;
 }

 void Warrior::attack(Character& opponent)
 {
    if(opponent.getType() == WARRIOR)
    {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if(opp.getAllegiance() == allegiance)
        {
            cout << "Warrior " << getName() << " does not attack Warrior " << opp.getName() << "." << endl;
            cout << "They share an allegiance with " << getAllegiance() << "." << endl;
            return;
        }
    }
    cout << "Warrior " << getName() << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
    double totalDamage = (health/MAX_HEALTH) * attackStrength;
    opponent.damage(totalDamage);
    cout << opponent.getName() << " takes " << totalDamage << " damage." << endl;
 }
#include "Wizard.h"
#include "Character.h"

Wizard::Wizard(const string &name, 
                double health, 
                double attackStrength, 
                int rank)
 : Character(WIZARD, name, health, attackStrength), rank(rank) 
 {  }

 const int Wizard::getRank() const
 {
    return rank;
 }

 void Wizard::attack(Character &opponent)
 {
    cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
    double totalDamage = attackStrength;
    if(opponent.getType() == WIZARD)
    {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        double temprank = rank;
        double tempOppRank = opp.getRank();
        totalDamage = attackStrength * (temprank / tempOppRank);
    }
    opponent.damage(totalDamage);
    cout << opponent.getName() << " takes " << totalDamage << " damage." << endl;
}
 

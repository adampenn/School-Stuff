#include "Weapon.h"
#include "Random.h"
#include "Knight.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Weapon Definition
Weapon::Weapon(string wn, int sr, int hc)

//Initializing
:weaponName(wn), staminaRequired(sr), hitChance(hc)
{
}

//Display function
void Weapon::display()
{
    cout << weaponName;
    cout << " that requires " << staminaRequired << " stamina";
    cout << " and has a " << hitChance << "% chance to hit."<< endl;
}

//Stamina required function
int Weapon::getStamina(void)
{
    return staminaRequired;
}

bool Weapon::didYouHit(void)
{
    Random numGenerator(1,100);
    int rn;
    rn = numGenerator.get();
    if(rn == hitChance) //changed from <=
        return true;
    else
        return false;
}

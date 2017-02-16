#include"Weapon.h"
#include"Random.h"
#include"Knight.h"
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//Weapon Constructor Definition
Weapon::Weapon(string wn, int wsr, int whc)

//Weapon Initialization List
: weaponName(wn), weaponStaminaRequired(wsr), weaponHitChance(whc)

{

}



//Weapon Display Function
void Weapon::display()
{

    cout <<  " is using: " << weaponName << " that requires " << weaponStaminaRequired << " stamina and has a ";
    cout << weaponHitChance << "% chance to hit." << endl << endl;   
}


//Get Stamina Required Function
int Weapon::getStaminaRequired(void)
{
    return weaponStaminaRequired;
}


//Did You Hit Function
bool Weapon::didYouHit(void)
{
    Random theGenerator(1,100);
    int rn;
    rn = theGenerator.get();
    if (rn <= weaponHitChance)
        return true;
    else
        return false;
}

















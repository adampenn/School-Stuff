#include"Weapon.h"
#include"Knight.h"
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;



//Knight Constructor Definition
Knight::Knight(string kn, int ks, string wn, int wsr, int whc)

//Knight Initialization List
:knightName(kn), knightStamina (ks), weaponInHand(wn, wsr, whc), onHorse(true)

{

}


//Knight Display Function
void Knight::display(void)
{
    //First Line of Display
    cout << knightName << " is ";
    if(exhausted() == false)
        cout <<  "not exhausted";
    else
        cout << "exhausted";
        cout << " (stamina=" << knightStamina << ") and ";
    if(areYouOnHorse() == true)
        cout << "is still on horse." << endl;
    else
        cout << "has been knocked off the horse." <<endl;
    
    //Second Line of Display
    cout << knightName; /*<< " is using: " << weaponName << "that requires ";
    cout << weaponStaminaRequired << "and has a " << weaponHitChance;
    cout << " chance to hit." << endl; */
    weaponInHand.display();

}

//On Horse Function
bool Knight::areYouOnHorse(void)
{
    if(knightStamina > 0)
        return true;
        //onHorse = false;
    else
        return false;
        //onHorse = true;
}



//Exhausted Function
bool Knight::exhausted(void)
{
    if(knightStamina > 0)
        return false;
    else
        return true;
}




//Charge Function
bool Knight::charge(void)
{
    
    int x = weaponInHand.getStaminaRequired();  
    knightStamina-=x;

    return weaponInHand.didYouHit();
    
    
    //get did you hit;
    //return from weapon
}




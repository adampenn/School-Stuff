#include "Weapon.h"
#include "Knight.h"
#include "Random.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Knight definition
Knight::Knight(string kn, int ks, string wn, int sr, int hc)
:knightName(kn), knightStamina(ks), weaponInHand(Weapon(wn, sr, hc))
{
}

//Display function
void Knight::display()
{
  cout << knightName << " is ";
    if(exhausted() == false)
        cout << "not exhausted ";
   else
        cout << "exhausted";
  cout << "(stamina = ";
  cout << knightStamina << ") and";

    if(onHorse() == true)
       cout << " is still on the horse." << endl;
    else
       cout << " has been knocked off the horse." << endl;
       cout << knightName << " is using: ";
       weaponInHand.display();
}
//On horse function
bool Knight::onHorse(void)
{
    if(knightStamina <= 0)
        return false;
    else 
        return true;
}
//Exhausted function
bool Knight::exhausted(void)
{
    if(knightStamina > 0) 
        return false;
    else
        return true;
}

//Charge function
bool Knight::charge(void)
{
      int callStaminaFunction = weaponInHand.getStamina();
      knightStamina = knightStamina - callStaminaFunction;

      return weaponInHand.didYouHit();
}        

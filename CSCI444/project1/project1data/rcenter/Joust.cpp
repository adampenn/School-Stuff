//FILE NAME: Joust
//AUTHOR: Rod Center
//DATE: 10 November 2015
//

#include <iostream>
#include <string> 
#include "Weapon.h"
#include "Knight.h"
#include "Random.h"

using namespace std;

int main()
{
  int StaminaReserve, StaminaCost, HitPercent;
  int StaminaReserve2, StaminaCost2, HitPercent2;
  
  string Name, Name2, Type, Type2;

  bool OnHorse, Exhausted; 

cout << "\n\n\n*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*\n";
cout << "\n \n Hello, Welcome to the Joust test program\n\n\n";
//user inputs for Knight(1)
cout << "*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*X*\n\n";
cout << "Please enter in the necessary values for the 1st Knight:\n\nName: ";
getline(cin, Name);
cout << "Stamina reserve: ";
cin >> StaminaReserve;

cin.ignore();
cout << "\n****************************\n\n";
cout << "Please enter in the values for the 1st weapon:\n\nType: ";
getline(cin, Type);
cout << "Stamina cost: ";
cin >> StaminaCost;
cout << "Percent Hit Chance: ";
cin >> HitPercent;

//build Knight
Knight K1(Type, StaminaCost, HitPercent, StaminaReserve, Name, OnHorse, Exhausted);

cin.ignore();
//user inputs for Knight(2)
cout << "******************************\n\n";
cout << "Please enter in the necessary values for the 2nd Knight:\n\nName: ";
getline(cin, Name2);
cout << "Stamina reserve: ";
cin >> StaminaReserve2;

cin.ignore();
cout << "\n****************************\n\n";
cout << "Please enter in the values for the 2nd weapon:\n\nType: ";
getline(cin, Type2);
cout << "Stamina cost: ";
cin >> StaminaCost2;
cout << "Percent Hit Chance: ";
cin >> HitPercent2;

//build 2nd knight
Knight K2(Type2, StaminaCost2, HitPercent2, StaminaReserve2, Name2, OnHorse, Exhausted);


// check if exhausted, on horse
// charge() loop
bool K1OnHorse, K1exhausted, K2OnHorse, K2exhausted;
K1OnHorse = K1.GetHorseStatus();
K1exhausted = K1.GetExhausted();
K2OnHorse = K2.GetHorseStatus();
K2exhausted = K2.GetExhausted();
do
{
	//check status in loop
bool K1OnHorse, K1exhausted, K2OnHorse, K2exhausted;
K1OnHorse = K1.GetHorseStatus();
K1exhausted = K1.GetExhausted();
K2OnHorse = K2.GetHorseStatus();
K2exhausted = K2.GetExhausted();

if(K1OnHorse == true && K1exhausted == false && K2OnHorse == true && K2exhausted == false)

  {

     bool x, y;
     K1.StaminaMath();
     x = K1.Charge();
       if (x == true)
      {
        K2.SetOffHorse();
      }
  
    K2.StaminaMath();
    y = K2.Charge();
      if (y == true)
      {
        K1.SetOffHorse();
      }

    K1.display();
    K2.display();


  }

  else
{
cout << "\n\n__________________________________________________________________\n\nEnd of Match\n\n";
cout << "__________________________________________________________________\n";

return 0;
}

}while(K1OnHorse == true && K1exhausted == false && K2OnHorse == true && K2exhausted == false);

}

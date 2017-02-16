//Alona Bransford
//// 11/12/2015
//// project 4
////http://www.cplusplus.com


// includes
#include<iostream>
#include<string>
#include<stdio.h>
#include<cstdlib>
#include"Random.h"
#include "Knight.h"


using namespace std;

//Main
int main(void)
{
 //Declaration of variables
  int loopcontinue = 0;

  int knight1out;
  int knight2out;
  int weaponstamina;


  int knightstamina;

  
  int weaponhitchance;

  int round = 1;

  string name;

  string nameofweapon;

  Knight knight1;

  Knight knight2;

 system("clear");
  cout<< endl << "Knights Joust Battle1" <<endl<<  endl;

// Asks for the Knights information 
// Which are NAME , weapon , chance to hit , stamina , stamina required for weapon
// For loop will run for 2 knights 
for(int i = 0;i<2;i++)
{
  cout<<endl <<"Knight "<< i+1 <<endl<< "Name :" ; 

  getline (cin,name);

  cout<<"stamina? :";

  cin>>knightstamina;

  cin.ignore(256, '\n');

  cout<<"weapon? :";

  getline (cin,nameofweapon);

  cout<<"Required Stamina for Weapon ? :";

  cin>>weaponstamina;

  cout<<"Chance to hit of the Weapon ? (%):";

  cin>>weaponhitchance;

  cin.ignore(256, '\n');

  if(i== 0)
{
  knight1.setstats(name,knightstamina, nameofweapon,weaponstamina, weaponhitchance);
}

else if(i == 1)
{
  knight2.setstats(name,knightstamina,nameofweapon,weaponstamina, weaponhitchance);
}

}
system("clear");

// Shows the Knights Stats before Joust
cout << "Before Battle Summary "<< endl<< endl << endl;


knight1.showstats();
cout << endl << endl;
knight2.showstats();

// Jousts until Knights are Exhausted or knoocked from horse
  do
  {
    cout << endl << endl;
    cout<<" ROUND "<< round <<endl;
    
// If the Attack suceeded , Knight 2 will be knocked out , and vice versa
    if(knight1.attack())
{
      knight2.isKnocked();
} 
   if(knight2.attack())
{ 
     knight1.isKnocked();
}
    knight1.showstats();
    cout<<endl<<endl;
    knight2.showstats();
    cout << endl<< endl;

    round = round + 1;

// Calculates if Knights Fell off or Exausted
  knight1out = (!knight2.knightIsExausted() && knight2.onhorse());
  knight2out = (knight1.onhorse() && !knight1.knightIsExausted()); 
  loopcontinue = knight1out && knight2out;

  }while(loopcontinue);



  return 0;
}

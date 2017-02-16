//Randell Gallardo
#include "Random.h"
#include "weapon.h"
#include "knight.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
  int stamina, stam_req, hit_chance, i=1; //creating variables
  string name, weapon_name, weapon_n; 
  knight knight1, knight2;
  cout <<"Welcome to the Tournament of Champions" << endl;
  cout << endl;



  //Assigning Warrior 1 parameters
  cout <<"Warrior 1" << endl << "Knight's Name:" << endl;
  getline (cin, name); 

  cout <<"Stamina:";
  cin >> stamina;
  cin.ignore();

  cout <<"What Weapon does Warrior 1 choose:" << endl;
  getline(cin, weapon_name);

  cout <<"Stamina Required:";
  cin >> stam_req;
  cin.ignore();
  cout << stam_req << endl;

  cout <<"Weapon's hit chance (1 in 4)"<< endl;
  cin >> hit_chance;
  cin.ignore();

  knight1.set(name, stamina,weapon_name,  stam_req, hit_chance);

  cout << endl;




  //Assigning Warrior 2 parameters 
  cout <<"Warrior 2" << endl << "Knight's Name:" << endl;
  getline (cin, name);

  cout <<"Stamina:";
  cin >> stamina;
  cin.ignore();

  cout <<"What Weapon does Warrior 2 choose:" << endl;
  getline(cin, weapon_name);

  cout <<"Stamina Required:";
  cin >> stam_req;
  cin.ignore();
  cout << stam_req << endl;

  cout <<"Weapon's hit chance (1 in 4)" << endl;
  cin >> hit_chance;
  cin.ignore();

  knight2.set(name, stamina,weapon_name, stam_req, hit_chance);

  do //loop for joust rounds
  {
    cout << " Round " << i << endl; //if you are not exhausted attack else you get kicked off horse
    if(!knight1.exhausted())
    {
      if(knight1.attack())
        knight2.kicked_off();
    }else 
      knight1.kicked_off();
    if(!knight2.exhausted())
    {

      if(knight2.attack())
        knight1.kicked_off();
    }else
      knight2.kicked_off();
    //output results
    knight1.display();
    cout << endl << endl;
    knight2.display();

    ++i; //counts the rounds
  }
  while( ( !knight1.exhausted() && knight1.onhorse() ) && ( !knight2.exhausted() && knight2.onhorse() ) );
  //repeat while knights are not exhausted and on horse 
  if(knight1.onhorse())
  {
    if(knight2.onhorse())
    {
      cout <<"somtething broke" << endl;
    }else 
      cout <<"\nWarrior 1 wins the golden joust" << endl;
  }
  else 
  {
    if(knight2.onhorse())
    {
      cout <<"\nWarrior 2 wins the golden joust" << endl;
    }
    else
      cout <<"\nIt is a tie!" << endl;
  }
  return 0;
}



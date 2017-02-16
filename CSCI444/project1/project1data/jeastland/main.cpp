/*
 * Name: Joeann Eastland
 * Project #: 4
 * Joust
 * Date: 11/12/2015
 Main File: Joust


*/


//// Files & Libraries: ///////

#include "Knight.h"
#include "Weapon.h" 
#include "Random.h"
#include <iostream>
using namespace std;


int main()
{
  int stamina, stam_req, hit_chance, i=1;
  string name, weapon_name;
  ////////// Welcome Page//////////
  cout << "Welcome to Joust Game!" << endl;
  cout << "Enter 1st  Knght's Name: "; // Ask for name
  getline(cin, name);
  cout << "Enter your Stamina: ";
  cin >> stamina;
  cin.ignore(1000, '\n');
  cout << "Enter your Weapon's Name:";
  getline(cin, weapon_name);
  cout <<"Enter the Weapon's Stamina Required:";
  cin >> stam_req;
  cout << "Enter Weapon's hit chance (%)";
  cin >> hit_chance;
  Weapon w1(weapon_name, stam_req, hit_chance);
  cin.ignore(1000, '\n');
  Knight Knight1(name, stamina, weapon_name, stam_req, hit_chance);



  cout << "Enter 2nd  Knght's Name: ";
  getline(cin, name);
  cout << "Enter your Stamina: ";
  cin >> stamina;
  cin.ignore(1000, '\n');
  cout << "Enter your Weapon's Name:";
  getline(cin, weapon_name);
  cout <<"Enter the Weapon's Stamina Required:";
  cin >> stam_req;
  cout << "Enter Weapon's hit chance (%)";
  cin >> hit_chance;
  Weapon W2(weapon_name, stam_req, hit_chance);
  cin.ignore(1000, '\n');
  Knight Knight2(name, stamina, weapon_name, stam_req, hit_chance);



  do 
  {
    cout << "\n\n\n Round" << i << endl;
    if (Knight1.attack())
    {
      Knight2.unhorse();
      cout << Knight2.get_name() << " was unhorse by " << Knight1.get_name()

        << "!" << endl;
    }

    if (Knight2.onhorse())
    {
      if (Knight2.attack())
      {
        Knight1.unhorse();
        cout << Knight1.get_name() << " was unhorsed by " << Knight2.get_name()
          << "!" << endl;
      }
    }

    if (Knight1.exhausted())
    {
      cout << Knight1.get_name() << " is exhausted!" << endl;
    }
    if (Knight2.exhausted())
    {
      cout << Knight2.get_name() << " is exhausted!" << endl;
    }

    Knight1.display();
    cout << endl << endl;
    Knight2.display();

    i++;
  }while (!Knight1.exhausted() && Knight1.onhorse() && !Knight2.exhausted() && Knight2.onhorse());

  cout << "\n\n\n FINAL SCORE/AFTER" << i-1 << " round(s):\n";
  Knight1.display();
  cout<<endl<<endl;
  Knight2.display();
  cout<<endl;
  return 0;
}




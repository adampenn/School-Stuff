//Jackson Coit, CSCI 111
//Project 4: Joust 

#include<iostream>
#include"Random.h"
#include"Knight.h"
#include"Weapon.h"
#include<string>
using namespace std;

 int main()
  {
    int stamina, stam_req, hit_chance, i=1;
    string name, weapon_name, wep_sub;

    knight kn1, kn2;

    cout << "Welcome to the Joust" <<endl;
    cout << "Combatant #1" << endl << "Knight's Name: " << endl;
    getline (cin,name);

    cout << "Stamina: "; 
    cin >> stamina ;
    cin.ignore(1000, '\n');

    cout << "Their weapon: " << endl;
    getline (cin, weapon_name);

    cout << "Stamina required: ";
    cin >> stam_req;

    cout << "Weapon's hit chance (1 in 6): ";
    cin >> hit_chance;
    cin.ignore(1000, '\n');

    kn1.set(name, stamina, weapon_name, stam_req, hit_chance);
    
    cout << "\nCombatiant #2" << endl << "Knight's Name: ";
    getline (cin, name);

    cout << "Stamina: ";
    cin >> stamina;
    cin.ignore(1000, '\n');

    cout << "Their weapon: ";
    getline (cin, weapon_name);

    cout << "Stamina required: ";
    cin >> stam_req;

    cout << "Weapon's hit chance(1-6): ";
    cin >> hit_chance;

    kn2.set(name, stamina, weapon_name, stam_req, hit_chance);

    do
    {
      cout << "\n\n\nRound " << i << endl;

      if(kn1.attack())
        kn2.unhorse();
      if(kn2.attack())
        kn1.unhorse();

      kn1.display();
      cout << endl << endl;
      kn2.display();
      
      i++;
    } while (!kn1.exhausted() && kn1.onhorse() && !kn2.exhausted() && kn2.onhorse());

    return 0;
  }

      
      

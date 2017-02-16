// Name:Yousef Gherfal
// Project# 4
#include<iostream>
#include "Knight.h"
#include "Random.h"
#include "Weapon.h"
#include<string>
using namespace std;

int main()
{
  int stamina;
  int stam_req;
  int hit_chance;
  int i=1;
  string name, weapon_name;
  Knight K1, K2;

  cout << "Hello there, Welcome to the Jousting game" <<endl;
  cout << "Type in your first Knight's name: "<<endl;
  getline(cin,name);
  cout << "His Stamina: ";
  cin >> stamina;
  cin.ignore(1000, '\n');
  cout << "His Weapon: "<<endl;
  getline(cin,weapon_name);
  cout << "Stamina required: ";
  cin >> stam_req;
  cout << "Weapon's hit chance (1 in 6): ";
  cin >>hit_chance;
  cin.ignore(1000, '\n');
  K1.set(name, stamina, weapon_name, stam_req, hit_chance);

  cout << "Type in your second Knight's name: "<<endl;
  getline(cin,name);
  cout << "His Stamina: ";
  cin >> stamina;
  cin.ignore(1000, '\n');
  cout << "His Weapon: "<<endl;
  getline(cin,weapon_name);
  cout << "Stamina required: ";
  cin >> stam_req;
  cout << "Weapon's hit chance (1 in 6): ";
  cin >>hit_chance;
  cin.ignore(1000, '\n');
  K2.set(name, stamina, weapon_name, stam_req, hit_chance);
  
  do
  {
    cout <<"\n\n\nRound " << i << endl;
    if(K1.attack())
      K2.unhorse();
    if(K2.attack())
      K1.unhorse();

    K1.display();
    cout << endl;
    K2.display();

    i++;
  }while(!K1.exhausted() && K1.onhorse() && !K2.exhausted() && K2.onhorse());

  return 0;
}

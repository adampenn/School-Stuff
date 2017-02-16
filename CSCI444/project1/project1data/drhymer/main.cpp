// Donnetta Rhymer
// main.cpp
#include<iostream>
#include<string>
#include"Random.h"
#include"weapon.h"
#include"knight.h"
using namespace std;

int main() {


int stamina, staminaRequired, hit_chance, i=1;
string name, weapon_name;
Knight kn1, kn2;

//   10 Questions

cout << "Welcome to the Royal Joust! Let us begin!" << endl;

cout << "What is the first knight's name?" << endl;
getline(cin, name);
cout << "How much stamina does " << name << " have?" << endl;
cin >> stamina;
cout << "The weapon of choice is:";
getline(cin, weapon_name);
cout << "Stamina required for use is:";
cin >> staminaRequired;
cout << "The weapon's hit chance:";
cin >> hit_chance;
kn1.set(name, stamina, weapon_name, staminaRequired, hit_chance);

cout << "What is the second knight's name?" << endl;
getline(cin, name);
cout <<"How much stamina does " << name << " have?" << endl;
cin >> stamina;
cout << "The weapon of choice is:";
getline(cin, weapon_name);
cout << "Stamina required for use is:";
cin >> staminaRequired;
cout << "The weapon's hit chance:";
cin >> hit_chance;
kn2.set(name,stamina, weapon_name, staminaRequired, hit_chance);


//    Actual Joust


do
{
cout << "Round" << i << endl;

if(kn1.attack())
  kn2.unhorse();
if(kn2.attack())
  kn1.unhorse();

kn1.display();
cout << endl<< endl;
kn2.display();

i++;
}while(!kn1.exhausted() && kn1.onhorse() && !kn2.exhausted() && kn2.onhorse());

  


  return 0;
}

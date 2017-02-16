// Hiroko Sockwell, joust.cpp
#include<iostream>
#include<string>
#include<fstream>
#include"Knight.h"
#include"Random.h"
using namespace std;

int main()
{
  Random r(1,100);
  int stamina = 0;
  int staminaCost = 0;
  int hitChance = 0;
  int input;
  ifstream stats;
  stats.open("stats.txt");
  stats.ignore(256,':');
  stats >> input;
  //construct two knights with (onHorse, stamina, knightName, staminaCost, hitChance, weaponName)
  //if the stats.txt file is set to be used accept values from it otherwise accept manual input
  if (input == false) {
    stats.ignore(256,':');
    stats >> stamina;
    stats.ignore(256,':');
    stats >> staminaCost;
    stats.ignore(256,':');
    stats >> hitChance;
  }
  else if (input == true) {
    cout << "Please enter stamina of Knight 1 and the cost and hit chance of his weapon." << endl << "stamina: ";
    cin >> stamina;
    cout << "stamina cost: ";
    cin >> staminaCost;
    cout << "hit chance out of 100: ";
    cin >> hitChance;
    cout << endl;
  }
  Knight k1(true, stamina, "Sir Cuss", staminaCost, hitChance, "Lance");
  if (input == false) {
    stats.ignore(256,':');
    stats >> stamina;
    stats.ignore(256,':');
    stats >> staminaCost;
    stats.ignore(256,':');
    stats >> hitChance;
  }
  if (input == true) {
    cout << "Please enter stamina of Knight 2 and the cost and hit chance of his weapon." << endl << "stamina: ";
    cin >> stamina;
    cout << "stamina cost: ";
    cin >> staminaCost;
    cout << "hit chance out of 100: ";
    cin >> hitChance;
    cout << endl;
  }
  Knight k2(true, stamina, "Lancelot", staminaCost, hitChance, "Sword");
  stats.close();

  k1.display();
  k2.display();
  while (k1.lost() == false && k2.lost() == false) {
    //charge using a number from the random number generater then return true if hit to unhorse enemy Knight
    k2.unhorsed(k1.charge(r.get()));
    k1.unhorsed(k2.charge(r.get()));
    k1.display();
    k2.display();
  }
  //show how the victorious Knight won
  if ((k1.horse() == true && k2.horse() == true && k1.tired() == true && k2.tired() == true) || (k1.horse() == false && k2.horse() == false))
    cout << "It's a tie" << endl;
  else if (k1.tired() == true && k2.horse() == true || k1.horse() == false)
    k2.won(k1.horse());
  else if (k2.tired() == true && k1.horse() == true || k2.horse() == false)
    k1.won(k2.horse());

  return 0;
}

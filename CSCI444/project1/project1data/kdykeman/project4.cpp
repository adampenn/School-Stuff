#include<iostream>
#include<string>
#include"Random.h"
#include"Knight.h"
#include"Weapon.h"

using namespace std;

int main ()
{
string names;
int newstam;
string wchoice;
int sreq;
int cha;
cout << "What is the 1st Knight's name? ";
cin >> names;
cout << "What is the 1st Knight's stamina? ";
cin >> newstam;
cout << "What is the 1st Knight's weapon? ";
cin >> wchoice;
cout << "What is the required stamina by the " << wchoice<< "?";
cin >> sreq;
cout << "What is the " << wchoice << "'s hit chance? ";
cin >> cha;

cout << "Creating Knight 1: " << names << ", " << newstam << ", " << wchoice << ", " << sreq << ", " << cha << endl;
Knight knight1 (names, newstam, wchoice, sreq, cha);

cout << "What is the 2nd Knight's name? ";
cin >> names;
cout << "What is the 2nd Knight's stamina? ";
cin >> newstam;
cout << "What is the 2nd Knight's weapon? ";
cin >> wchoice;
cout << "What is the required stamina by the " << wchoice << "?";
cin >> sreq;
cout << "What is the "<< wchoice << "'s hit chance? ";
cin >> cha;

cout << "Creating Knight 2: " << names << ", " << newstam << ", " << wchoice << ", " << sreq << ", " << cha << endl;
Knight knight2(names, newstam, wchoice, sreq, cha);

  
  while(knight1.stamina()==false && knight2.stamina()==false && knight1.mounted()==true && knight2.mounted()==true)
  {
  bool hchance = knight1.charge();
  if (hchance)
  {
    knight2.dehorse();
  }
  hchance = knight2.charge();
  if (hchance)
  {
    knight1.dehorse();
  }
  knight1.display();
  knight2.display();
  }
}

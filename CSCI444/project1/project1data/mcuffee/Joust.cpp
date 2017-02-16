#include"Weapon.h"
#include"Random.h"
#include"Knight.h"
#include<string>
#include<iomanip>
using namespace std;

int main()
{
  Knight k1;
  Knight k2;
  Weapon w1;
  Weapon w2;

  string n;
  int st;

  cout << "Knight 1, enter thy name: " << flush;
 
  getline(cin, n);

  cout << n "," << "Provide your current stamina: " <<flush;

  cin >> st;

  cout << n "," << "What weapon do you possess: " << flush;

}


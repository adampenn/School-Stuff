#include<iostream>
#include<string>
#include"Random.h"
#include"Knight.h"
#include"Weapon.h"
using namespace std;

int main ()
{
string Kname;
int stam = 7;
string Wname;
int sr;
int hitc;
cout << "What is Knight #1's name? ";
cin >> Kname;
cout << "What is Knight #1's weapon? ";
cin >> Wname;
cout << "What is the " << wt << "'s stamina required? ";
cin >> sr;
cout << "What is the " << wt << "'s hit chace? ";
cin >> hitc;
cout << "Knight #1 stats: " << Kname << ", " << stam << ", " << Wname << ", " << sr << ", " << hitc << endl;
Knight k1(Kname, stam, Wname, sr, hitc);

cout << "What is Knight #2's name? ";
cin >> Kname;
cout << "What is Knight #2's weapon? ";
cin >> Wname;
cout << "What is the " << Wname << "'s stamina required? ";
cin >> sr;
cout << "What is the "<< Wname << "'s hit chance? ";
cin >> hitc;
cout << "Knight #2 stats: " << Kname << ", " << stam << ", " << Wname << ", " << sr << ", " << hitc << endl;
Knight k2(Kname, stam, Wname, sr, hitc);

  // charge
  while(k1.exhausted_check()==false && k2.exhausted_check()==false && 
        k1.horse_check()==true && k2.horse_check()==true)
  {
  bool check_hit = k1.charge();
  if (check_hit)
  {
    k2.unHorse();
  }
  check_hit = k2.charge();
  if(check_hit)
  {
    k1.unHorse();
  }
  k1.display();
  k2.display();
  }
}

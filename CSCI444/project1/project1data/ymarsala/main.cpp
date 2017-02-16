//Yolonda Marsala
//Project 4
//Last Edited Novmeber 12th

#include <iostream>
#include <string>
//#include "Weapon.cpp"
#include "Knight.cpp"
#include "Random.cpp"
using namespace std;

int main()
{
  string knightname1;
  string knightname2;
  int stam1;
  int stam2;
  string weapname1;
  string weapname2;
  int stamreq1;
  int stamreq2;
  int hitchance1;
  int hitchance2;
  bool knight1alive = true;
  bool knight2alive = true;
  cout << "What would you like to name knight 1?" << endl;
  cin >> knightname1;
  cout << "How much stamina does he have?" << endl;
  cin >> stam1;
  cout << "What is his weapon's name?" << endl;
  cin >> weapname1;
  cout << "How much stamina does it take to use?" << endl;
  cin >> stamreq1;
  cout << "What is the weapon's chance to hit?" << endl;
  cin >> hitchance1;
  Knight k1(knightname1, stam1);
  //Weapon w1(weapname1, stamreq1, hitchance1);

  cout << "What is the second knight's name?" << endl;
  cin >> knightname2;
  cout << "How much stamina does he have?" << endl;
  cin >> stam2;
  cout << "What is his weapon's name?" << endl;
  cin >> weapname2;
  cout << "How much stamina does it take to use?" << endl;
  cin >> stamreq2;
  cout << "What is the weapon's chance to hit?" << endl;
  cin >> hitchance2;
  Knight k2(knightname2, stam2);
  //Weapon w2(weapname2, stamreq2, hitchance2);
  cout << "NOW IT IS TIME TO JOUST!!!" << endl;

  do
  {
    cout << "Both knight's are ready" << endl;
    cout << "Charging" << endl;
    k1.gettired(stamreq1);
    k2.gettired(stamreq2);
    Random r(1,100);
    int rn1 = r.get();
    int rn2 = r.get();
    if (k1.getstam() > 0 && k2.getstam() > 0)
    {
      if(hitchance2 >= rn1)
      {
        cout << knightname1 << " was unhorsed!" << endl;
        knight1alive = false;
      }
      if(hitchance1 >= rn2)
      {
        cout << knightname2 << " was unhorsed!" << endl;
        knight2alive = false;
      }
    }
    else
    {
      if (k1.getstam() < 0)
      {
        cout << knightname1 <<  " has run out of stamina and can no longer joust!" << endl;
        knight1alive = false;
      }
      if (k2.getstam() < 0)
      {
        cout << knightname2 << " has run out of stamina and can no longer joust!" << endl;
        knight2alive = false;
      }
    }
  }while(knight1alive == true && knight2alive ==true);

  if(knight1alive == false)
  {
    cout << knightname2 << " is the victor! With his " << weapname2 <<  endl;
  }
  if(knight2alive == false)
  {
    cout << knightname1 << " is the victor! With his " << weapname1 << endl;
  }
  if(knight1alive == false && knight2alive == false)
  {
    cout << "That makes it a tie!" << endl;
  }

  return 0;
}


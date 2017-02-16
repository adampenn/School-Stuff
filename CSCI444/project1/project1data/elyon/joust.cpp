#include<iostream>
#include<string>
#include"knight.h"
using namespace std;
int main()
{
  string w,x,y,z;
  int a,b,c,d,e,f;
  cout << "Enter a name for knight 1" << endl;
  getline (cin,w);
  cout << "Enter a name for knight 2" << endl;
  getline (cin,x);
  cout << "What weapon is " << w << " using?" << endl;
  getline (cin,y);
  cout << "What weapon is " << x << " using?" << endl;
  getline (cin,z);
  cout << "How much stamina does " << w << " have?" << endl;
  cin >> a;
  cout << "How much stamina does " << x << " have?" << endl;
  cin >> b;
  cout << "How much stamina does " << y << " cost?" << endl;
  cin >> c;
  cout << "How much stamina does " << z << " cost?" << endl;
  cin >> d;
  cout << "What is the hit chance of " << y << "?" << endl;
  cin >> e;
  cout << "What is the hit chance of " << z << "?" << endl;
  cin >> f;
  knight knight_1(w,a,y,c,e);
  knight knight_2(x,b,z,d,f);
  cin.ignore();
  do{
    knight_1.display();
    knight_2.display();
    string xx;
    getline (cin,xx);
    bool k=knight_1.charge();
    if (k==true)
    {knight_2.unhorse_yourself();
     cout << w << " has hit " << x << endl;}
    else {cout << w << " missed his strike" << endl;}
    bool j=knight_2.charge();
    if (j==true)
    {knight_1.unhorse_yourself();
     cout << x << " has hit " << w << endl;}
    else {cout << x << " missed his strike" << endl;}
    if (k==false&&j==false)
    {
      cout << "press ENTER for next round" << endl;
      getline (cin,xx);
    }
  }
  while(knight_1.exhausted()==false&&knight_2.exhausted()==false&&knight_1.are_you_on_horse()==true&&knight_2.are_you_on_horse()==true);
 if (knight_1.exhausted()==true&&knight_1.are_you_on_horse()==true)
   cout << w << " is too tired to go on." << endl;
 if (knight_1.exhausted()==false&&knight_1.are_you_on_horse()==false)
   cout << w << " has fallen off their horse, but gets up and walks away" << endl;
 if (knight_1.exhausted()==true&&knight_1.are_you_on_horse()==false)
   cout << w << " has fallen off their horse and is too tired to get up." << endl;
 if (knight_2.exhausted()==true&&knight_2.are_you_on_horse()==true)
   cout << x << " is too tired to go on." << endl;
 if (knight_2.exhausted()==false&&knight_2.are_you_on_horse()==false)
   cout << x << " has fallen off their horse, but gets up and walks away" << endl;
 if (knight_2.exhausted()==true&&knight_2.are_you_on_horse()==false)
   cout << x << " has fallen off their horse and is too tired to get up." << endl;
 
 
 
 
 return 0;
}

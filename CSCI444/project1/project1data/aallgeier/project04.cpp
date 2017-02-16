#include<iostream>
#include<string>
#include"Weapon.h"
#include"Knight.h"
#include"Random.h"
using namespace std;
//other functions(none in this case), and the main-function
int main()
{
string knight;
  string wp;
  int hc;
  int sr;
  
 cout <<"Welcome to the Joust Game" <<endl;
   cout <<"You need to name Knights, choose Weapons, Hitchance and Stamina required." <<endl;
   cout <<"Name Knight1" <<endl;
   getline(cin,knight);
   cout <<"Choose Knight1's Weapon1"<<endl;
   getline(cin,wp);
   cout <<"Choose Weapon1's Hitchance"<<endl;
   cin >> hc;
   cout <<"Enter the Stamina Required for Weapon1 between 1 to 100"<<endl;
   cin >> sr;
  Weapon F1(wp, hc, sr);
  Knight P1(knight, F1);
   
   cout <<"Name Knight2" <<endl;
   getline(cin,knight);
   cout <<"Choose Knight2's Weapon2"<<endl;
   getline(cin,wp);
   cout <<"Choose Weapon2's Hitchance"<<endl;
   cin >> hc;
   cout <<"Enter the Stamina Required for Weapon2 between 1 to 100"<<endl;
   cin >> sr;
  Weapon F2(wp, hc, sr);
  Knight P2(knight, F2);

while(P1.still_on_horse() && P2.still_on_horse())
{
  bool H1, H2;
   H1 = P1.attack();
   H2 = P2.attack();
   if(H1)
   {
     P2.onhorse();
   }
   if(H2)
   {
     P1.onhorse();
   }

   if(P1.get_stamina_required() <= 0)
   {
     P1.onhorse();
     cout << P1.getknight() << " is exhausted. His stamina is "<< P1.get_stamina_required();
   }
   else 
   {
     cout << P1.getknight() << " isn't exhausted. His stamina is "<< P1.get_stamina_required();
   }
   if( P1.still_on_horse() )
   {
     cout << "He is still on the Horse" <<endl;
   }
   else
   {
     cout << "He drops down" << endl;
    }
  cout << P1.getknight() << " is using "<< P1.getweapon().getknight()<< " which used "<< P1.getweapon().get_stamina_required() << " stamina and has a "<< P1.getweapon().get_hit_chance() <<" hit chance to fight." <<endl;


if(P2.get_stamina_required() <= 0)
{
 P2.onhorse();
 cout << P2.getknight() << " is exhausted. His stamina is "<< P2.get_stamina_required();
}
else
{
 cout << P2.getknight() << " isn't exhausted. His stamina is "<< P2.get_stamina_required();
}
if (P2.still_on_horse() )
{
 cout << "He is still on the Horse" <<endl;
}
 else
{
 cout << "He drops down" << endl;
}

cout << P2.getknight() << " is using "<< P2.getweapon().getknight()<< " which used "<< P2.getweapon().get_stamina_required() << " stamina and has a "<< P2.getweapon().get_hit_chance() <<" hit chance to fight." <<endl;

}
return 0;

}
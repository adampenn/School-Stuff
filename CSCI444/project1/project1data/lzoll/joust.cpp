#include<iostream>
#include"Random.h"
#include"knight.h"
#include"weapon.h"
using namespace std;

int main()
{
  cout<<"Enter in the name of Knight one"<<endl;
  string knight1;
  getline(cin, knight1);
  cout<<"What is "<< knight1<< "'s stamina?"<<endl;
  int knight1_st;
  cin >>knight1_st;
  cout<<"Enter in the name of Knight two"<<endl;
  string knight2;
  cin.ignore();
  getline(cin, knight2);
  cout<<"What is "<< knight2<< "'s stamina?"<<endl;
  int knight2_st;
  cin >>knight2_st;
  cout<<"What is "<< knight1<< "'s weapon?"<<endl;
  string weapon1;
  cin.ignore();
  getline(cin, weapon1);
  cout<<"What is "<< knight2<<"'s weapon?"<<endl;
  string weapon2;
  getline(cin, weapon2);
  cout<<"What is "<< weapon1 <<"'s stamina cost"<<endl;
  int st1;
  cin >>st1;
  cout<<"what is it's chance of hitting?"<<endl;
  int hc1;
  cin >>hc1;
  cout<<"What is "<< weapon2<<"'s stamina cost?"<<endl;
  int st2;
  cin >>st2;
  cout<<"What is its chance of hitting?"<<endl;
  int hc2;
  cin>>hc2;
  knight knight_1(knight1, knight1_st, weapon1, st1, hc1);
  knight knight_2(knight2, knight2_st, weapon2, st2, hc2);

do 
{
  bool fight=knight_1.attack();
  if (fight==true)
  {
   knight_2.horse_status(); 
  };
  bool fight2=knight_2.attack();
  if (fight2==true)
  {
    knight_1.horse_status();
  };
  knight_1.display();
  knight_2.display();

}while(knight_1.exhausted()==false&&knight_2.exhausted()==false&&knight_1.are_you_on_horse()==true&&knight_2.are_you_on_horse()==true);
return 0;
}


















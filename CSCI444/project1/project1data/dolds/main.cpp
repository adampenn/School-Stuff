#include"knight.h"
#include"weapon.h"
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<iostream>
using namespace std;

int main()
{
  cout<<"Lets review our combatants shall we?"<<endl;
  cout<<"Over here we have...ah..hmm...what was their name again?"<<endl;
  string knight1,weapon1;
  getline(cin,knight1);
  system("clear");
  cout<<"And what was their weapon again?"<<endl;
  getline(cin,weapon1);
  system("clear");
  cout<<"Hmm, rather strange names this year..."<<endl;
  cout<<"Moving on! What did the evauluators rate their stamina as?"<<endl;
  int knight1stam,weapon1hit,weapon1cost;
  cin>>knight1stam;
  system("clear");
  cout<<"And how good where they at hitting with their chosen armament"<<endl;
  cout<<" between one and a one-hundred?"<<endl;
  cin>>weapon1hit;
  system("clear");
  cout<<"With a number, how quickly did they say the weapon tired them?"<<endl;
  cin>>weapon1cost;
  system("clear");

  cout<<"So... "<<knight1<<" has "<<knight1stam<<" stamina while weilding"<<endl;
  cout<<weapon1<<" which their ability to hit with it is rated as "<<weapon1hit<<endl;
  cout<<" which tires them at a rate of "<<weapon1cost<<endl;
  cout<<"...Rather dissapointing. I promised my daughter somthing"<<endl;
  cout<<"interesting would happen this year."<<endl;
  cout<<"*sigh*"<<"\n"<<"I guess I'll teaching her about dissapointment."<<endl;

  cout<<"Who are they going up against?"<<endl;
  string knight2,weapon2;
  cin.ignore();
  getline(cin,knight2);
  system("clear");
  cout<<"Dear GOD! Is no one around here a seriouse contender!?"<<endl;
  cout<<"What are THEY weilding, please tell me its interesting."<<endl;
  getline(cin,weapon2);
  system("clear");
  cout<<"Just stop trying. You were trying weren't you?"<<endl;
  cout<<"I guess its not as terrible as Sir longwick last year."<<endl;
  cout<<"\n"<<"We all still remember the ryhmes they made about him."<<endl;
  cout<<"\n"<<"Ok...wel...How good is their stamina?"<<endl;
  int knight2stam,weapon2hit,weapon2cost;
  cin>>knight2stam;
  system("clear");
  cout<<"Their ability to hit?"<<endl;
  cin>>weapon2hit;
  system("clear");
  cout<<"Truely the dissapointment never ends. How quickly do they tire?"<<endl;
  cin>>weapon2cost;
  system("clear");
  cout<<"So... "<<knight2<<" has "<<knight2stam<<" stamina while weilding"<<endl;
  cout<<weapon2<<" which their ability to hit with it is rated as "<<weapon2hit<<endl;
  cout<<" which tires them at a rate of "<<weapon2cost<<endl;
  cout<<"Is there nothing remarkable in this world? Already I tire of this"<<endl;
  cout<<"game. Sound the call, order them to charge!."<<endl;

  system("clear");
  Knight k1(knight1,weapon1,knight1stam,weapon1hit,weapon1cost);
  Knight k2(knight2,weapon2,knight2stam,weapon2hit,weapon2cost);

  bool k1stamflag,k2stamflag,k1mountedflag,k2mountedflag;
  do
  {
    k1.charge();
    k2.charge();

    k1.display();
    k2.display();

    k1stamflag=k1.are_you_exhausted();
    k1mountedflag=k1.are_you_mounted();
    k2stamflag=k2.are_you_exhausted();
    k2mountedflag=k2.are_you_mounted();

  }
  while (k1stamflag==false && k2stamflag==false && k1mountedflag==true && k2mountedflag==true);

  if(k1stamflag==false && k1mountedflag==true)
  {
    cout<<"That was probably the saddest attempt we've seen all day.."<<endl;
    cout<<"\n"<<"Go congratulate "<<knight1<<" on their pathetic vicotory."<<endl;
  }
  else if(k2stamflag==false && k2mountedflag==true)
  {
    cout<<"That was probably the saddest attempt we've seen all day.."<<endl;
    cout<<"\n"<<"Go congratulate "<<knight2<<" on their pathetic vicotory."<<endl;
  }
  else
  {
    cout<<"A tie? Neither one of them was superior to the other?"<<endl;
  }

  cout<<"Well I'm off to dinner, and to teach my daughter how to cope"<<endl;
  cout<<"with the pain of boredom and the sorrow of dissapointment."<<endl;
  return 0;
}


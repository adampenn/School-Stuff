//Tessa Vong 
//Project 4 Joust
//Worked with 07 Beta class group 
//Referenced lectures, labs, and online site 
//https://github.com/aelberling/CSCI-111/blob/master/joust.cpp

#include<iostream>
#include<cstdlib>
#include<string>
#include"Knight.h"
#include"Weapon.h" 
using namespace std; 

int main()
{
  int stamina, stam_req, hit_chance, i=1; 
  string name, weapon_name; 
  Knight kn1, kn2; 

  cout<<"Welcome to the Jousting Tournament"<<endl; 
  cout<<"Player 1: Choose your player."<<endl;
  cout<<"1. King George(100 stamina)."<<endl; 
  cout<<"2. Sir Luke(150 stamina)."<<endl; 
  int choice;  
  cin>>choice;
   
  switch(choice)
  { 
     case 1: 
       cout<<"You selected King George."<<endl; 
       name="King George"; 
       stamina=100; 
       break;  
     
     case 2: 
         cout<<"You selected Sir Luke."<<endl; 
         name="Sir Luke"; 
         stamina=150; 
         break;  
     default: 
         cout<<"Not a valid choice."<<endl; 
     
  } 
   cout<<"Select a weapon:"<<endl; 
   cout<<"1. Spear (Stam req=50, Hit Chance 20%)"<<endl;
   cout<<"2. Mace (Stam req=60, Hit Chance 35%)"<<endl;
   cin>>choice;

  switch(choice)
  {
    case 1: 
      cout<<"You selected spear."; 
      stam_req=50; 
      hit_chance=20; 
      weapon_name="spear"; 
      break; 

    case 2: 
      cout<<"You selected Mace."; 
      stam_req=60; 
      hit_chance=35; 
      weapon_name="mace"; 
      break;

    default: 
      cout<<"Not a valid choice."<<endl; 
   } 
 kn1.set(name, stamina, weapon_name, stam_req, hit_chance); 


cout<<"Player 2: Select a Knight."<<endl; 
cout<<"1.King George(100 Stamina)."<<endl; 
cout<<"2.Sir Luke(150 Stamina)."<<endl; 
cin>>choice; 

switch(choice)
   {
      case 1:
       cout<<"You selected King George."<<endl;
       name="King George";
       stamina=100;
       break; 
     
      case 2:
      cout<<"You selected Sir Luke."<<endl;
      name="Sir Luke";
      stamina=150;
      break; 

      default:
      cout<<"Not a valid choice."<<endl;
     
 }
    cout<<"Select a weapon:"<<endl;
    cout<<"1. Spear (Stam req=50, Hit Chance 20%)"<<endl;
    cout<<"2. Mace (Stam req=60, Hit Chance 35%)"<<endl;
    cin>>choice;

switch(choice)
   {
     case 1:
      cout<<"You selected spear."<<endl;
      stam_req=50;
      hit_chance=20;
      weapon_name="spear";
      break;
                       
     case 2:
      cout<<"You selected Mase."<<endl;
      stam_req=60;
      hit_chance=35;
      weapon_name="mase";
      break;
                              
     default:
       cout<<"Not a valid choice."<<endl;
   }
kn2.set(name, stamina, weapon_name, stam_req, hit_chance);



 do
   { 
     cout<<"\nRound"<<i<<endl; 
     if(kn1.attack())
       kn2.unhorse(); 
     if(kn2.attack())
       kn1.unhorse(); 

     kn1.display(); 
     cout<<endl;
     kn2.display(); 

     i++; 
   }while(!kn1.exhausted() && kn1.onhorse() && !kn2.exhausted() && kn2.onhorse());

cout<<"\nStats "<< i-1<<" Round(s):"<<endl; 
kn1.display(); 
cout<<endl; 
kn2.display();
cout<<endl; 

return 0; 
 }

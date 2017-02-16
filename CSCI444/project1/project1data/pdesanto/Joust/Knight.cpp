#include <iostream>
#include <iomanip>
#include "Knight.h"

using namespace std;


     bool Kinght::pass()
        {
            if(stam>0)
            {
        stam= stam- weapon_in_hand.get_stam();

        if(weapon_in_hand.hit())
            return true;
        else
            return false;
        }else
            return false;
   }

   bool Knight::exhausted()
   {
    if (stam>0)
        return false;
    else 
   
   return true;
   }

   bool Knight::onhorse()
   {
    if(on_horse)
        return true;
    else
        return false;
   }

   void Knight::unhorse()
   {
    on_horse = false;
   }
                    
    void Knight::display()
       {
          cout<< name << " is ";
          if(on_horse){
            cout<< "on his horse, ";
         } else
            cout<< "off his horse, ";
           if(exhausted()){
            cout<<"and is exhausted";
          }  else
               cout << "Stamina: " << stam << endl;
               cout< name<< "'s weapon is";
               weapon_in_hand.display();
    }


#include"knight.h"
#include"weapon.h"
#include<iostream>
#include<string>
using namespace std;

//class definition
bool Knight::attack()
{
  if(stamina > 0)
  {
    stamina=stamina - weapon_in_hand.get_stamina();
    if(weapon_in_hand.hit())
      return true;
    else
      return false;
  }else
    return false;
}

void Knight::unhorse()
{
  on_Horse = false;
}

bool Knight::exhausted()
{
  if (stamina>0)
    return false;
  else
    return true;
}

bool Knight::onhorse()
{
  if(on_Horse)
    return true;
  else
    return false;
}

void Knight::display()
{
  cout<<name<<" is currently ";
  if (on_Horse)
    cout<<"on the horse, ";
  else
    cout<<"off the horse, ";
  if(exhausted())
    cout<<"and is exhausted \n";
  else
    cout<<"with "<<stamina<<" points of stamina.\n";
  cout<<name<<" is holding a ";
  weapon_in_hand.display();
}

void Knight::show()
{
  cout<<name<<", has "<<stamina<<" stamina" <<endl;
}

//Same as the getter methods in weapon.cpp , get_stamina() and get_name returns the
// value of whichever variable the method is suppose to track
int Knight::get_stamina(){
	return stamina;
}

string Knight::get_name(){
	return name;
}

//setter methods such as set_name , set_stamina and set_wep_in_hand allow the external classes
//who are using an object instance of this class ( e.g. in main.cpp where i define kn3 kn4 and kn5 they are all
// object isntances of this class knight.cpp ( object is called "Knight" ) , to be able to change the
// variables of the object through these methods , this logic applies for getter methods ( get_etc methods )
// as well where it allows the value of the variables to be seen through the getter methods instead of getting
// it direct from the object as this is proper encapsulation ( as the variables are private , but the getter/setter methods
// are public )
void Knight::set_name(string n){
	name=n;
}

void Knight::set_stamina(int sta){
	stamina=sta;
}

void Knight::set_weapon_in_hand(Weapon wep){
	weapon_in_hand = wep;
}

void Knight::set_on_Horse(bool oH){
	on_Horse = oH;
}

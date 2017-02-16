#include<iostream>
#include"knig.h"
using namespace std;

Knight::Knight(string n, bool h, int s)
  : knight_name(n), on_horse(h), knight_stamina(s)
{
}

bool Knight::horse_or_naw()
{
  bool yesOrNo;
  yesOrNo=on_horse;
  return yesOrNo;
}

bool Knight::exhausted()
{
  if (knight_stamina > 0)
    return false;
  else
    return true;
}
/*
bool Knight::charge()
{

}
*/
void Knight::display()
{
  cout << knight_name <<" is"; 
  if (knight_stamina > 0)
    cout << " not";
  cout << " exhausted (stamina = " << knight_stamina << "), and is ";
  if (on_horse == false)
    cout << "off their horse." <<endl;
  else 
    cout << "still on their horse." <<endl;
}

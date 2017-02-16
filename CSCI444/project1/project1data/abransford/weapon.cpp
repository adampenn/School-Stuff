// weapon class

#include<iostream>
#include"Random.h"
#include<string>

using namespace std;

class weapon
{
// Declaration of private variables
  private:
  int neededstamina;
  int weaponhitchance;
  string nameWeapon;
  
// Set the stats for weapons
  public:
  void setstats(string wname, int staminaneed, int hitchance)
	{
  nameWeapon=wname;
  neededstamina=staminaneed;
  weaponhitchance=hitchance;

	}
// Display Weapon Stats
  void showstats()
	{
  cout<<nameWeapon<<" that Requires "<<neededstamina<<" stamina and has a "
      <<weaponhitchance <<"% chance to hit";

	}
 // return needed stamina for weapon
 int show_stamina()
	{

 	return neededstamina;

	}
// Calculates if the weapon hits using random number generator
  bool weaponhit()
	{

 Random hitchance(1,100);

  if (hitchance.get() <= weaponhitchance)
    return 1;
  else
    return 0;


	}
};

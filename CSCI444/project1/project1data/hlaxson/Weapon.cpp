#include "Weapon.h"
#include "Random.h"
#include <iostream>

Weapon::Weapon(string wep_name, int hit_chance, int stamina_req) // constructor
: wep_name_m(wep_name), hit_chance_m(hit_chance), stamina_req_m(stamina_req) // initialization list
{

}
bool Weapon::hit()
{
	Random rand(0, 100);
		int number = rand.get();
		
		if (hit_chance_m >= number)
			return true;
		else
			return false;
		
}

int Weapon::get_stamina()
{
	return stamina_req_m;
}

void Weapon::display()
{
	cout << "Weapon: " <<wep_name_m<<endl;
	cout << "Hit Chance: " <<hit_chance_m<< "% "<<endl;
	cout << "Stamina Req: " <<stamina_req_m<<endl;
}

#include <string>
#include <iostream>
#include "Knight.h"
#include "Weapon.h"

using namespace std;

Knight::Knight(string name, string wep_name, int hit_chance, int stamina_req, int stamina) // constructor
: knt_weapon(wep_name, hit_chance, stamina_req), knt_name(name), on_horse(true), knt_stamina(stamina) // initialization list
{
}
bool Knight::mounted()
{
	return on_horse;
}

bool Knight::did_hit()
{
	knt_stamina = knt_stamina - knt_weapon.get_stamina();
	return knt_weapon.hit();
}
int Knight::current_stamina()
{
	return knt_stamina;
}
void Knight::knockoff()
{
	on_horse = false;
}

void Knight::display()
{
	cout << knt_name<<endl;
	knt_weapon.display();
	cout << knt_name<<"'s Stamina: "<<knt_stamina<<endl;
  cout << "On Horse: "<<on_horse<<endl;
  cout << ""<<endl;
}

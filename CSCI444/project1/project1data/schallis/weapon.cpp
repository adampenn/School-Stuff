#include"weapon.h"
#include"Random.h"

weapon::weapon(string w, int sr, int hc) {
	Weapon = w;
	StRq = sr;
	HitC = hc;
}

bool weapon::getHitC()
{Random rd(0,100);

	if (rd.get() <= HitC)
		return true;
	else
		return false;
}

int weapon::getStRq()
{
return StRq;
}
void weapon::displayw()
{
	cout << Weapon << " that requires " << StRq << " stamina and has a " << HitC << "% chance to hit the opponent" << endl;
}

string weapon::getWeapon()
{
	return Weapon;
}


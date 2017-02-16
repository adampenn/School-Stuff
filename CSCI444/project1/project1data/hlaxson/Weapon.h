#ifndef WEAPON_H
#define WEAPON_H
#include <string>
using namespace std;

class Weapon
{
public:
	Weapon(string wep_name, int hit_chance, int stamina_req);
	int get_stamina();
	bool hit();
	void display();
private:
	string wep_name_m;
	int hit_chance_m;
	int stamina_req_m;
};
#endif
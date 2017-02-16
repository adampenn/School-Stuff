#ifndef KNIGHT_H
#define KNIGHT_H
#include "Weapon.h"
#include <string>

class Knight
{
public:
	Knight(string name, string weapon, int hit_chance, int stamina_req, int stamina);
	bool mounted();
	int current_stamina();
	void knockoff();
	void display();
    bool did_hit();
private:
	string knt_name;
	Weapon knt_weapon;
	bool on_horse;
	int knt_stamina;

};
#endif

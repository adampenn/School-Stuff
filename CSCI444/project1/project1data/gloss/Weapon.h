#ifndef WEAPON_H
#define WEAPON_H
#include <string>
using namespace std;

class Weapon
{
    public:
    	Weapon(string n, int a, int b);
		int get_stamina_required(void);
		void wdisplay1();
		void wdisplay2();
		bool did_you_hit(void);
	private:
		string name;
		int hit_chance;
		int stamina_required;
};
#endif

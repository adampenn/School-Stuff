#ifndef KNIGHT_H
#define KNIGHT_H
#include "Weapon.h"
#include <string>
using namespace std;


class Knight {
	public:
		Knight(string n, int stam, string ty, int sr, int hc);
		bool attack();
		bool is_knight_exhausted();
		void unhorse_yourself();
		void display1();
		void display2();
		bool on_horse;
	private:
		int stamina;
		string name;
		Weapon weapon_in_hand;


};
#endif

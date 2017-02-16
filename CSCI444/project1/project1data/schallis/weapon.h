#include<iostream>
#include<string>
using namespace std;

class weapon {
	private:
		string Weapon;
		int StRq;
		int HitC;
	public:
		int getStRq();
		bool getHitC();
		string getWeapon();
		void displayw();
		weapon(string w, int sr, int hc);
};


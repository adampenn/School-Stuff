#include"weapon.h"
#include<iostream>
#include<string>
using namespace std;

class knight {
	private:
		int Stamina;
		bool OnHorse;
		string Name;
		weapon wc;
	public:
		knight(string n, int s, string w, int sr, int hc);
		int getStamina();
		int Reds();
		bool getHorse();
		bool getDidYouHit();
		bool GetOffHorse();
		void display();
		void unhorsed();
};


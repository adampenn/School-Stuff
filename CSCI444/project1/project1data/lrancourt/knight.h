#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include"weapon.h"

class knight
{
public:
	knight(string name, int stamina) 
		: _name(name), _stamina(stamina), _onhorse(true) {}
	~knight();

	//getters
	int getStamina();
	bool getHorseStatus();
	string getWeapon();
	string getName();

	//setters
	void setWeapon(weapon* w);
 
	bool hit();
	void unhorse();
private:
	int _stamina;
	bool _onhorse;
	string _name;
	weapon* _w;	
};

#endif

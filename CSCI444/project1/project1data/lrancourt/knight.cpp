#include"knight.h"

knight::~knight()
{
	delete _w;
}

int knight::getStamina()
{
	return _stamina;
}

bool knight::getHorseStatus()
{
	return _onhorse;
}

string knight::getWeapon() 
{
	return _w->getName();
}

string knight::getName()
{
	return _name;
}

void knight::setWeapon(weapon* w)
{
	_w = w;
}

bool knight::hit()
{
	_stamina -= _w->getStamUse();

	if(_stamina < 0)
	{
		_stamina = 0;
	}

	return _w->getHit();
}

void knight::unhorse()
{
	_onhorse = false;
}

#include"weapon.h"

#include<cstdlib>
#include<iostream>

bool weapon::getHit()
{
	Random r(1, 100);
	int rand = r.get();
		
	if(rand <= _hitChance)
	{
		return true;
	}
	else
		return false;
}

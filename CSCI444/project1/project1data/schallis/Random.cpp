#include<iostream>
#include<cstdlib>
#include<cstddef>
#include<ctime>

#include"Random.h"

int Random::seedcount=0;

void Random::seed(void)
{
	if(seedcount) return;
	seedcount=1;
	srand((int)time(0));
}

Random::Random(int l, int h) : low (l), diff(abs(h-l)+1)
{
	seed();
}

int Random::get(void) const
{
	return int((float)rand()/RAND_MAX*diff+low);
}


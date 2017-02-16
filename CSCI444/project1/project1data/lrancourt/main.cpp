#include<iostream>

#include"system.h"

using namespace std;

int main()
{
	system s;

	s.gameInit();
	
	while(s.getRunning())
	{
		s.run();
		s.update();
		s.display();
	}

	return 0;
}

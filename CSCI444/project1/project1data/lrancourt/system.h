#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include"knight.h"

#include<string>
#include<vector>

using namespace std;

class system
{
public:
	system();
	~system();

	bool getRunning();
	
	void gameInit();
	
	void run();
	void update();
	void display();	
private:
	vector<knight*> _klist;
	vector<string> _msg;

	int _round;
	bool _running;	
};

#endif

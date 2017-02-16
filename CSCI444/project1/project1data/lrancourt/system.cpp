#include<iostream>
#include<vector>

#include"system.h"

system::system()
{
	_running = true;
	_round = 0;
}

system::~system()
{
	for(int i = 0; i < _klist.size(); i++)
	{
		delete _klist[i];
	}
}

bool system::getRunning()
{
	return _running;
}

void system::gameInit()
{
	string pname, cname;
	int pstam, cstam;
	int choice;
	
	cout << "give your knight a name: " << endl;
	cin >> pname;
	cout << "what is your knights stamina?" << endl;
	cin >> pstam;
	cout << "give the computer a name: " << endl;
	cin >> cname;
	cout << "what is the computers stamina?" << endl;
	cin >> cstam;
	cout << endl;

	knight* _player = new knight(pname, pstam);
	_klist.push_back(_player);

	knight* _comp = new knight(cname, cstam);
	_klist.push_back(_comp);

	for(int i = 0; i < _klist.size(); i++)
	{
		int hitChance, stamUse;
		string name;

		cout << "create a weapon for " << _klist[i]->getName();
		cout << endl;
		cout << "weapon name: ";
		cin >> name;
		cout << "hit chance: ";
		cin >> hitChance;
		cout << "stamina required: ";
		cin >> stamUse;
		
		weapon* w = new weapon(hitChance, stamUse, name);
		
		_klist[i]->setWeapon(w);	
	}	
}

void system::run()
{
	bool hit[2];
	string tmp;
	
 	for(int i = 0; i < _klist.size(); i++)
	{
		if(_klist[i]->getHorseStatus() && (_klist[i]->getStamina() > 0))
		{
			hit[i] = _klist[i]->hit();
		}
	}

	for(int i = 0; i < _klist.size(); i++)
	{
		if(hit[i] == true)
		{
			_klist[1 - i]->unhorse();

			tmp = _klist[i]->getName() + " landed a hit!";
			_msg.push_back(tmp);

			tmp = _klist[1 - i]->getName() + " was unhorsed!";
			_msg.push_back(tmp);

			_running = false;
		}
		else
		{
			tmp = _klist[i]->getName() + " missed!";
			_msg.push_back(tmp);
		}

		if(_klist[i]->getStamina() == 0)
		{
			_klist[i]->unhorse();
			
			tmp = _klist[i]->getName() + " is exausted!";
			_msg.push_back(tmp);
		}
	}	
}

void system::update()
{
	string tmp;

	for(int i = 0; i < _klist.size(); i++)
	{
		if(!_klist[i]->getHorseStatus())
		{
			_running = false;
		}	
	}

	for(int i = 0; i < _klist.size(); i++)
	{
		if(_klist[i]->getHorseStatus() && _running)
		{	
			tmp = _klist[i]->getName() + " gets ready for the next round";
			_msg.push_back(tmp);	
		}	
	}

	if(!_running)
	{
		tmp = " ";
		_msg.push_back(tmp);

		tmp = "game over!";
		_msg.push_back(tmp);
	}

	_round++;	
}

void system::display()
{
	cout << endl;
	cout << "round " << _round << "!" << endl;

	for(int i = 0; i < _klist.size(); i++)
	{
		cout << endl;
		cout << "knight " << _klist[i]->getName() << endl;
		cout << "weapon: " << _klist[i]->getWeapon() << endl;
		cout << "stamina: " << _klist[i]->getStamina() << endl;
	}

	cout << endl;

	int msgsize = _msg.size();

	for(int i = 0; i < msgsize; i++)
	{
		cout << _msg[i] << endl;
	}
	
	for(int i = 0; i < msgsize; i++)
	{
		_msg.pop_back();	
	}
	
}

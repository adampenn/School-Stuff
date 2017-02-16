#include "Knight.h"
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <ctime>
using namespace std;

Knight::Knight(string n, int stam, string ty, int sr, int hc)
 : weapon_in_hand(ty, hc, sr), name(n), stamina(stam), on_horse(true)
{

}


bool Knight::attack()
{
	int sr;
	sr=weapon_in_hand.get_stamina_required();
	stamina-=sr;
	return weapon_in_hand.did_you_hit();
}

bool Knight::is_knight_exhausted()
{
	if(stamina<=0)
		return true;
	else
		return false;
}

void Knight::unhorse_yourself()
{
	on_horse=false;
}

void Knight::display1()
{
	cout<<"Knight "<<name<<endl;
	cout<<name<<"s stamina: "<<stamina<<endl;
	weapon_in_hand.wdisplay1();
}

void Knight::display2()
{
	cout<<"  Knight "<<name;
	cout<<" using weapon ";
	weapon_in_hand.wdisplay2();
	if(on_horse==true)
		cout<<" is on his horse and ";
	else
		cout<<" is not on his horse and ";
	if(is_knight_exhausted()==true)
		cout<<"is exhausted."<<endl;
	else
		cout<<"is not exhausted. And shall continue to fight."<<endl;
}

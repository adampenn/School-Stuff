#include "Weapon.h"
#include "Knight.h"
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <ctime>
using namespace std;

int main()
{
	string k1_name,k2_name,w1_type,w2_type;
	int k1_stamina,k2_stamina;
	int w1_hc,w2_hc;
	int w1_sr,w2_sr;

	cout<<endl;
	cout<<"Tell me brave knight, what is your name? "<<endl;
	cin>>k1_name;
	cout<<"And how much stamina do you have "<< k1_name << "?" <<endl;
	cin>>k1_stamina;
	cout<<"Marvelous. And what will you be wielding today? "<<endl;
	cin>>w1_type;
	cout<<"A superb weapon, what do you believe your chance to strike is? (1-100)" <<endl;
	cin>>w1_hc;
	cout<<"And what stamina does it require for you wield such a weapon? "<<endl;
	cin>>w1_sr;

	cout<<"Do you know your opponets name?"<<endl;
	cin>>k2_name;
	cout<<"How much stamina do they have? "<<endl;
	cin>>k2_stamina;
	cout<<"And I am sure they is wielding a fierce weapon, do you know what the name of the weapon is? "<<endl;
	cin>>w2_type;
	cout<<"What's the chance to hit someone with a weapon like that "<<endl;
	cin>>w2_hc;
	cout<<"what kind of stamina does that use? "<<endl;
	cin>>w2_sr;
	cout<<endl;

	Knight k1(k1_name, k1_stamina, w1_type, w1_sr, w1_hc);
	Knight k2(k2_name, k2_stamina, w2_type, w2_sr, w2_hc);

	k1.display1();
	k2.display1();
	cout<<endl;


	while(k1.is_knight_exhausted()==false && k2.is_knight_exhausted()==false && k1.on_horse==true && k2.on_horse==true)
	{
		cout<<"*                                                                             *"<<endl;

		bool hit;

		hit=k1.attack();
		if(hit==true)
			k2.unhorse_yourself();

		hit=k2.attack();
		if(hit==true)
			k1.unhorse_yourself();

		k1.display2();
		k2.display2();
	}




return 0;
}

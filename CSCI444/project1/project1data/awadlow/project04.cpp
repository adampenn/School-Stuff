#include<iostream>
#include"Joust.h"
using namespace std;

int main()
{
	string your_name;
	string your_wname;
	int your_hitchance;
	int your_stamina_cost;
	int your_stamina;
	bool your_exhausted;
	bool your_unhorsed;
	
	string opponent_name;
	string opponent_wname;
	int opponent_hitchance;
	int opponent_stamina_cost;
	int opponent_stamina;
	bool opponent_exhausted;
    	bool opponent_unhorsed;

	int choice=0;
	while (choice!=2)
	{
		cout<<"-----------------------------------------------------------"<<endl;

		Joust j(your_name,your_wname,your_hitchance,your_stamina_cost,your_stamina,your_exhausted,your_unhorsed , opponent_name,opponent_wname,opponent_hitchance,opponent_stamina_cost,opponent_stamina,opponent_exhausted,opponent_unhorsed  );

		j.reset_knight();
		
		j.type_your_name();

		j.choose_your_weapon();
		j.generate_opponent_weapon();
		j.display_weapon();
		
		j.pause();

		j.display_knight();

		j.pause();
		j.judge();
		int judge;
		int turn=0;
		judge=j.judge();
		while(judge==0)
		{
			cout<<"\n\n\n\n_______________Roound:"<<++turn<<"_______________\n\n\n"<<endl;
			j.pause();
			j.round();
			j.judge();
			judge=j.judge();
			j.pause();
			if (j.judge()==0){cout<<"\nNext Round"<<endl;}
			
		}
		if (j.judge()==1){cout<<"\n\n\n\nJoust over\n_________Your Knight Win!!_________\n\n\n\n\n"<<endl;}
		if (j.judge()==2){cout<<"Joust over\n_________Tie!!_________\n\n\n\n\n"<<endl;}
		if (j.judge()==3){cout<<"Joust over\n_________opponent Knight Win!!_________\n\n\n\n\n"<<endl;}

		
		cout<<"Would you want try again?\n"<<endl;
		cout<<"type in     1 for yes , 2 for no"<<endl;

		cin>>choice;

	}
	return 0;
}

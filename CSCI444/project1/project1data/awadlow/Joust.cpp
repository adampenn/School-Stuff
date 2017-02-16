#include<iostream>
#include"Joust.h"
#include"Random.h"

using namespace std;

Joust::Joust(string yn,string ywn,int yhc,int ysc,int ys,bool ye,bool yuh , string on,string own,int ohc,int osc,int os,bool oe,bool ouh  )
	: your_name(yn), your_wname(ywn), your_hitchance(yhc), your_stamina_cost(ysc), your_stamina(ys), your_exhausted(ye), your_unhorsed(yuh), opponent_name(on), opponent_wname(own), opponent_hitchance(ohc), opponent_stamina_cost(osc), opponent_stamina(os), opponent_exhausted(oe), opponent_unhorsed(ouh)
{ 
}



void Joust::round()
{	
	Random your_hit(1,100);
	int yhit=your_hit.get(); 

	Random oppo_hit(1,100);
	int ohit=oppo_hit.get();

	if (your_hitchance>yhit)
	{opponent_unhorsed=1; cout<<"\n\nYou hit opponent!"<<endl;}
	else{cout<<"\nYou miss"<<endl;}

	if (opponent_hitchance>ohit)
	{your_unhorsed=1; cout<<"You have been hit!"<<endl;}
	else{cout<<"Opponent miss"<<endl;}

	your_stamina = your_stamina - your_stamina_cost;
	opponent_stamina = opponent_stamina - opponent_stamina_cost;
	
	if(your_stamina<1)
	{your_exhausted=1; cout<<"\nYour stamina come to zero!"<<endl;}
	else{cout<<"\nYour stamina remain--"<<your_stamina<<endl;}

	if(opponent_stamina<1)
	{opponent_exhausted=1; cout<<"Opponent stamina come to zero!"<<endl;}
	else{cout<<"Opponent stamina remain--"<<opponent_stamina<<endl;}
}

int Joust::judge()
{
	int you_beaten=0;
	int opponent_beaten=0;

	if (your_unhorsed || your_exhausted){you_beaten=1;}
	if (opponent_unhorsed || opponent_exhausted){opponent_beaten=1;}
	
	if(you_beaten==1 && opponent_beaten==1){return 2;}

	if(you_beaten==0 && opponent_beaten==1){return 1;}

	if(you_beaten==1 && opponent_beaten==0){return 3;}

	if(you_beaten==0 && opponent_beaten==0){return 0;}

}

void Joust::pause()
{
	cout<<"\n(Type in any charactor to continue)-------------------------------------------"<<endl;
	char wsedrftgyujiko;
	cin>>wsedrftgyujiko;
}

void Joust::type_your_name()
{
	cout<<"Please type the name of your Knight"<<endl;	
	string n;
	getline(cin,n);
	your_name=n;
}


void Joust::choose_your_weapon()
{
	char your_w='0';
	while (your_w!='4' && your_w!='1' && your_w!='2' && your_w!='3')	
	{
		cout<<"\n\nPlease choose your weapon"<<endl;
		cout<<"\n1.Blast Ax--(hitchance 69%, staminacost 50)  \n2.Lance--(hitchance 62%, staminacost 34)  \n3.Sword--(hitchance 57%, staminacost 25)  \n4.Iron Stick--(hitchance 50%, staminacost 20)"<<endl;		
		cin>>your_w;
		if (your_w!='4' && your_w!='1' && your_w!='2' && your_w!='3'){your_w='0';}
	}
	if (your_w=='1')
	{  your_hitchance=49; your_stamina_cost=50; your_wname="\"Blast Ax\"";}
	if (your_w=='2')
	{  your_hitchance=42; your_stamina_cost=34; your_wname="\"Lance\"";}
	if (your_w=='3')
	{  your_hitchance=37; your_stamina_cost=25; your_wname="\"Sword\"";}
	if (your_w=='4')
	{  your_hitchance=30; your_stamina_cost=20; your_wname="\"Iron Stick\"";}
}

void Joust::generate_opponent_weapon()
{
	Random o_weapon(1,4); //creates 'r'. This variable can generate random numbers between 1-100
	int rn=o_weapon.get(); //generate a random number and assign it to rn
	if (rn==1)
	{  opponent_hitchance=69; opponent_stamina_cost=35; opponent_wname="\"Blast Ax\"";}
	if (rn==2)
	{  opponent_hitchance=62; opponent_stamina_cost=33; opponent_wname="\"Lance\"";}
	if (rn==3)
	{  opponent_hitchance=57; opponent_stamina_cost=25; opponent_wname="\"Sword\"";}
	if (rn==4)
	{  opponent_hitchance=50; opponent_stamina_cost=20; opponent_wname="\"Iron Stick\"";}
}

void Joust::display_weapon()
{
	cout<<"\n\n_______________Weapon State_______________"<<endl;
	cout<<"--Your weapon:"<<your_wname<<"  --Hitchance:"<<your_hitchance<<"  --Stamina Cost:"<<your_stamina_cost<<endl;

	cout<<"\n--Opponent's weapon:"<<opponent_wname<<"  --Hitchance:"<<opponent_hitchance<<"  --Stamina Cost:"<<opponent_stamina_cost<<"\n\n"<<endl;
}


void Joust::display_knight()
{
	cout<<"\n\n_______________Knight State_______________"<<endl;
	string youh;
	if (your_unhorsed==0) {youh="Yes";}
	else {youh="No";} 
	
	string youe;
	if (your_stamina<1){youe="Yes";}
	else {youe="No";}
	cout<<"--Your Knight:\""<<your_name<<"\"  --Still on horse?:"<<youh<<" --Are you exhousted?:"<<youe<<"  --Stamina left:"<<your_stamina<<endl;

	string oppoh;
	if (opponent_unhorsed==0) {oppoh="Yes   ";}
	else {oppoh="No   ";} 
	
	string oppoe;
	if (opponent_stamina<1){oppoe="Yes   ";}
	else {oppoe="No   ";}
	cout<<"\n\n--Opponent Knight:"<<opponent_name<<"  --Still on horse?:"<<oppoh<<" --Is opponent exhousted?:"<<oppoe<<"  --Stamina left:"<<opponent_stamina<<"\n\n"<<endl;	
}

void Joust::reset_knight()
{	
	your_stamina=100;
	your_unhorsed=0;
	your_name="";
	your_exhausted=0;
	opponent_unhorsed=0;
	opponent_exhausted=0;
	opponent_stamina=100;
	opponent_name="\"Knight Barny\"";
}

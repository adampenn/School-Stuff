//Joust by Hortense Rush
#include"Random.h"
#include"knight.h"
#include"weapon.h"
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int main(){
  system("clear");
  cout << "What is your name?" << endl;
  string n; int round=1;
  getline(cin,n);
  
  string wep=""; int n1; int n2;
  
  cout << "How much Stamina do you have?" << endl;
  int sta1; cin >> sta1;
  cout << "How much Stamina does the Opponent have?" << endl;
  int sta2; cin >> sta2;  
  cout << "What is the name of your Weapon?" << endl;
  cin.ignore(); string wepp; getline(cin,wepp);
  cout << "What is the name of the Opponent's Weapon?" << endl;
  cin.ignore(); string wepe; getline(cin,wepe);
  cout << "How much Stamina does your Weapon Cost?" << endl;
  int cost1; cin >> cost1;
  cout << "How much Stamina does the Opponent's Weapon Cost?" << endl;
  int cost2; cin >> cost2;
  cout << "What is your Weapon's Hit Chance?" << endl;
  int hit1; cin >> hit1;
  cout << "What is the Opponent Weapon's Hit Chance?" << endl;
  int hit2; cin >> hit2;  
  cin.ignore();
  
  /*while(true){
	  system("clear");
	  cout << "Choose a weapon." << endl;
	  cout << "1) Sword (Stamina Cost:15 - Hit%:10)" << endl;
	  cout << "2) Lance (Stamina Cost:20 - Hit%:15)" << endl;
	  cout << "3) Pike  (Stamina Cost:35 - Hit%:25)" << endl;
	  string nn="";
	  getline(cin,nn);
	  if (nn=="1"){
		wep="Sword"; n1=15; n2=10;
		break;
	  }
	  if (nn=="2"){
		wep="Lance"; n1=20; n2=15;
		break;
	  }
	  if (nn=="3"){
		wep="Pike"; n1=35; n2=25;
		break;
	  }
  }*/

  Knight player(n,true,sta1,wepp,cost1,hit1);
  Knight enemy("Enoch",true,sta2,wepe,cost2,hit2);
  
  ////////////////Round Loop
  while(true){
  	system("clear");
	cout << "Round " << round << endl;
	cout << "---------" << endl;
	cout << player.displayName() << " is " << player.isExhausted() << " (stamina=" << player.Stam() << ") and " << player.isOffHorse() << "." << endl;
	cout << player.displayName() << " is using: " << player.displayWep() << " that requires " << player.StamCost() <<  " stamina and has a " << player.ShowChance() << "% to hit." << endl;
	cout << endl;
	
	cout << enemy.displayName()  << " is " << enemy.isExhausted()  << " (stamina=" << enemy.Stam()  << ") and " << enemy.isOffHorse()  << "." << endl;
	cout << enemy.displayName() << " is using: " << enemy.displayWep() << " that requires " << enemy.StamCost() <<  " stamina and has a " << enemy.ShowChance() << "% to hit." << endl;
	cout << endl;
	cout << "Press Enter to Joust!" << endl;
	string s;
	getline(cin,s);
	
	int gameover=0;
	int didhit=0;
	////Player Calculation
	if (player.Charge(enemy.displayName())){
		didhit=1;
	}
	////Enemy Calculation
	if (enemy.Charge(player.displayName())){
		didhit=2;
	}
	////Misc Calculations
	if (didhit==1){ enemy.Hit(); }
	if (didhit==2){ player.Hit();}
	
	
	if (didhit==0 && (!player.onHorse2() || !enemy.onHorse2() || !player.NotTired() || !enemy.NotTired())){
		if (!player.onHorse2() || !player.NotTired()){
			gameover=1;
		}
		if (!enemy.onHorse2() || !enemy.NotTired()){
			if (gameover==1){
				gameover=3;
			}else{
				gameover=2;
			}
		}
	}
	if (gameover==1){
		cout << "Game Over. You lost..." << endl; break;
	}
	if (gameover==2){
		cout << "Game Over. You won!" << endl; break;
	}
	if (gameover==3){
		cout << "Game Over. It's a draw." << endl; break;
	}
	
	round+=1;
	getline(cin,s);
  }
}

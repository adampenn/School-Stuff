//Joust by Hortense Rush
#include"Random.h"
#include"knight.h"
#include<iostream>
#include<string>
using namespace std;


Knight::Knight(string x, int y, int z, string t, int n1, int n2)
	: name(x), onHorse(y), stamina(z), wep(t,n1,n2)
{
}

string Knight::isOffHorse(){
	string oh;
	if (this->onHorse==true){
		oh="is still on the horse";
	}else{
		oh="has been knocked off the horse";
	}
	return oh;
}
bool Knight::onHorse2(){
	return onHorse;
}

string Knight::isExhausted(){
	string ex;
	if (this->stamina<=0){
		ex="exhausted";
	}else{
		ex="not exhausted";
	}
	return ex;
}
bool Knight::NotTired(){
	if (this->stamina>0){
		return true;
	}else{
		return false;
	}
}

int Knight::Stam(){
	return this->stamina;
}
string Knight::displayName(){
	return this->name;
}

string Knight::displayWep(){
	return wep.displayWep();
}
int Knight::StamCost(){
	return wep.StamCost();
}
int Knight::ShowChance(){
	return wep.ShowChance();
}

bool Knight::Charge(string n){
	this->stamina-=wep.StamCost();
	bool bo=false;
	if (this->onHorse2()==true){
		if (wep.didHit(wep.ShowChance())==true){
			cout << this->name << " hits " << n << "!" << endl;
			bo=true;
		}else{
			cout << this->name << " misses " << n << "." << endl;
			bo=false;
		}
	}else{
		cout << this->name << " can no longer continue." << endl;
		bo=false;		
	}
	if (this->NotTired()==false){
		cout << this->name << " collapses from exhaustion." << endl;
	}
	return bo;
}

void Knight::Hit(){
	this->onHorse=false;
}

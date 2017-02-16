//Ginette Mckamey CSCI 111

#include<iostream>
#include<iomanip>
#include"Weapon.h"
#include"Knight.h"
#include"Random.h"
using namespace std; 
int main()
{
  int K1stamina, K2stamina;
  int K1stamina_required, K2stamina_required;
  int K1hit_chance, K2hit_chance;
  string K1name, K2name;
  string K1weapon_type, K2weapon_type;

  cout << "What is the name of the first knight?" << endl;
  getline(cin, K1name);
  cout << "What is stamina required for " << K1name << "?" << endl;
  cin >> K1stamina; 

  cout << "What is the knights choice of weapon?" << endl;
  cin >> K1weapon_type;
  cout << "How much stamina does the " << K1weapon_type << " require?"<< endl;
  cin >> K1stamina_required;

  cout << "How much hit chance does your " << K1name << " have?" << endl;
  cin >> K1hit_chance;

  cout << "What is the name of the second knight?" << endl;
  cin >> K2name; 
  cout << "What is stamina required for " << K1name << "?"  << endl;
  cin >> K2stamina; 

  cout << "What is the knights choice of weapon?" << endl;
  cin >> K2weapon_type;
  cout << "How much stamina does the " << K2weapon_type << " require?"<< endl;
  cin >> K2stamina_required;

  cout << "How much hit chance does your " << K2name << " have?" << endl;
  cin >> K2hit_chance;

 Knight K1(K1name, K1stamina, K1weapon_type, K1stamina_required, K1hit_chance);
 Knight K2(K2name, K2stamina, K2weapon_type, K2stamina_required, K2hit_chance);
 
while(K1.are_you_exhausted()==false && K2.are_you_exhausted()==false && K1.are_you_on_horse()==true && K2.are_you_on_horse()==true)
{
 bool result;

result=K1.charge();
if(result==true)
  K2.unhorse_yourself();

result=K2.charge();
if(result==true)
  K1.unhorse_yourself();
}
K1.display();
K2.display();
cout << endl;
}

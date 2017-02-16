//Raphael "The Don" Gorga
//Project 4 - The Joust
#include<iostream>
#include<string>
#include"weap.h"
#include"knig.h"
using namespace std;

int main()
{
  cout << endl;
  cout << "Welcome to The Joust" <<endl;
  cout << "--------------------" <<endl;
  cout << endl;

  string k1_name;
  int k1_stamina;
  bool k1_on_horse = true;
  string w1_name;
  int w1_stamina_req;
  int w1_hit_chance;

  string k2_name;
  int k2_stamina;
  bool k2_on_horse = true;
  string w2_name;
  int w2_stamina_req;
  int w2_hit_chance;

  cout << "What is the name of the first knight?" <<endl;
  getline(cin, k1_name);
  cout << "What is the stamina of the first knight?" <<endl;
  cin >> k1_stamina;
  cout << "What weapon is the first knight using?" <<endl;
  cin.ignore();
  getline(cin, w1_name);
  cout << "How much stamina does " << w1_name << " require to wield?" <<endl;
  cin >> w1_stamina_req;
  cout << "What is the % hit chance of " << w1_name << "?" <<endl;
  cin >> w1_hit_chance;

  cout << "What is the name of the second knight?" <<endl;
  cin.ignore();
  getline(cin, k2_name);
  cout << "What is the stamina of the second knight?" <<endl;
  cin >> k2_stamina;
  cout << "What weapon is the second knight using?" <<endl;
  cin.ignore();
  getline(cin, w2_name);
  cout << "How much stamina does " << w2_name << " require to wield?" <<endl;
  cin >> w2_stamina_req;
  cout << "What is the % hit chance of " << w2_name << "?" <<endl;
  cin >> w2_hit_chance;
  cout <<endl;

  cout << "The Joust will last until a knight falls from their horse." <<endl;
  cout << "Commence Joust? (y/n)" <<endl;
  char commence;
  cin >> commence;
  if(commence == 'y')
  {
    do 
    {
      cout <<endl;
      cout << "--------------CHARGE--------------" <<endl;
      cout <<endl;

      Knight k1(k1_name, k1_on_horse, k1_stamina);
      Weapon w1(w1_name, w1_stamina_req, w1_hit_chance);
      Knight k2(k2_name, k2_on_horse, k2_stamina);
      Weapon w2(w2_name, w2_stamina_req, w2_hit_chance);

      k1_on_horse = k1.horse_or_naw();
      k2_on_horse = k2.horse_or_naw();

      k1.display();
      w1.display();
      cout <<endl;
      k2.display();
      w2.display();

     if (k1_on_horse == true)
     {
       int stamina_subtracted;
       stamina_subtracted = w1.get_stamina_cost();
       k1_stamina = (k1_stamina - stamina_subtracted);

       bool unhorse_or_naw;
       unhorse_or_naw = w1.did_you_hit();
       if (unhorse_or_naw == true || k2_stamina <= 0)
       {
         k2_on_horse = false;
       }
     }

     if (k2_on_horse == true)
     {
       int stamina_subtracted;
       stamina_subtracted = w2.get_stamina_cost();
       k2_stamina = (k2_stamina - stamina_subtracted);

       bool unhorse_or_naw;
       unhorse_or_naw = w2.did_you_hit();
       if (unhorse_or_naw == true || k1_stamina <= 0)
       {
         k1_on_horse = false;
       }
     }
    }
    while (k1_on_horse == true && k2_on_horse == true);

      cout <<endl;
      cout << "----------JOUST COMPLETE----------" <<endl;
      cout <<endl;

      Knight k1(k1_name, k1_on_horse, k1_stamina);
      Weapon w1(w1_name, w1_stamina_req, w1_hit_chance);
      Knight k2(k2_name, k2_on_horse, k2_stamina);
      Weapon w2(w2_name, w2_stamina_req, w2_hit_chance);

      k1.display();
      cout <<endl;
      k2.display();
      cout <<endl;
  }
  else if(commence == 'n')
  {
    cout <<endl;
    cout << "Goodbye" <<endl;
  }

  return 0;
}


//Suzanne Challis - Joust Project 4
#include<iostream>
#include<string>
#include"knight.h"

using namespace std;
int main()
{
  int i=1;	
  string n1;
  string n2;
  string w1;
	string w2;
	int sr1;
	int hc1; 
	int s1;
  int sr2;
  int hc2;
  int s2;
  cout << "" << endl;
	cout << "What is the first knight's name?" << endl;
	cin >> n1;
	cout << "What is the knight's stamina?" << endl;
	cin >> s1;
	cout << "What weapon are you using?" << endl;
	cin >> w1;
	cout << "What is the weapon's hit chance?" << endl;
	cin >> hc1;
	cout << "What is the required stamina to use this weapon?" << endl;
	cin >> sr1;
  cout << "" << endl;
	knight k1(n1,s1,w1,sr1,hc1);
	cout << "What is the second knight's name?" << endl;
	cin >> n2;
	cout << "What is the knight's stamina?" << endl;
	cin >> s2;
	cout << "What weapon are you using?" << endl;
	cin >> w2;
	cout << "What is the weapon's hit chance?" << endl;
	cin >> hc2;
	cout << "What is the required stamina to use this weapon?" << endl;
	cin >> sr2;
  cout << "" << endl;
	knight k2(n2,s2,w2,sr2,hc2);

  //Do loop to run the program using a counter i++ for the rounds

	do
  {
   cout<< "Round " << i << endl; 
    if (k1.getDidYouHit() == true)
		k2.unhorsed();
		if (k2.getDidYouHit() == true)
			k1.unhorsed();

		k1.display();
		k2.display();
cout<< "" <<endl;
cout<< "" <<endl;
		if (k1.GetOffHorse() == true && k2.GetOffHorse() == false)
    {
      cout <<"Knight "<<  n1 << "  won because " <<"Knight " << n2 << "  was knocked off of their horse" << endl;
      cout << "" << endl;
    }	
      if (k2.GetOffHorse() == true && k1.GetOffHorse() == false)
      {	
        cout << "Knight " << n2 << "  won because " <<"Knight "<<  n1 << "  was knocked off of their  horse" << endl;
      cout << "" << endl;
      }
		if (k1.GetOffHorse()  == false && k2.GetOffHorse()  == false)
    {	
      cout << "It's a tie, both knights knocked each other off their horses" << endl;
      cout << "" << endl;
    }
		if (k1.getStamina() <=0 && k2.getStamina() >0)
    {	
      cout <<"Knight "<<  n2 << "  wins because " << "Knight " <<n1 <<  " collapsed due to exhaustion" << endl;
      cout << "" << endl;
 }	
      if (k2.getStamina() <=0 && k1.getStamina() >0)
      {	
        cout <<"Knight " <<  n1 << "  wins because " <<"Knight "<<  n2 << "  collapsed due to exhaustion" <<endl;
      
        cout << "" << endl;
      }	
        if (k1.getStamina() <= 0 && k2.getStamina() <= 0) 
        {	
          cout << "Its a tie, both knights collapsed from exhaustion!" << endl;
      cout << "" << endl;
        }
i++;	
  } while (k1.GetOffHorse() == true && k2.GetOffHorse() == true && k1.getStamina() >= 0 && k2.getStamina() >= 0);

return 0;
}


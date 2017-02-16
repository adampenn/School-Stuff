/*Project 4 
 * Joust
 * Fabian Wuensche
 */
#include<iostream>
#include"Knight.h"
#include"Weapon.h"
#include"Random.h"
#include<string>
using namespace std;

int main()
{
  string n, wn;
  int s, wh, ws;
  char play;
  bool hit, mount1 = true, mount2 = true;
  cout << "Hello, welcome to the Joust! What is the first knight's name?" << endl;
  getline(cin,n);
  cout << "How much stamina does " << n << " have?" << endl;
  cin >> s;
  cin.ignore();
  cout << "What weapon is " << n << " using?" << endl;
  getline(cin,wn);
  cout << "How much stamina does a " << wn << " require to weild?" << endl;
  cin >> ws;
  cin.ignore();
  cout << "What is the hit chance of a " << wn << "?(enter a number between 1-100)" << endl;
  cin >> wh;
  cin.ignore();
  Knight k1(n, s, wn, ws, wh);
  cout << "What is the second knigth's name?" << endl;
  getline(cin,n);
  cout << "How much stamina does " << n << " have?" <<endl;
  cin >> s;
  cin.ignore();
  cout << "What weapon is " << n <<" using?" << endl;
  getline(cin, wn);
  cout << "How much stamina does a " << wn << " require to weild?" << endl;
  cin >> ws;
  cin.ignore();
  cout << "What is the hit chance of a " << wn << "?(enter a number between 1-100)" << endl;
  cin >> wh;
  cin.ignore();
  Knight k2(n, s, wn, ws, wh);
  k1.display(mount1);
  k2.display(mount2);
  cout << "Ready set Joust!!(press enter to start)" << endl;
  cin.get();
  do 
  {
    k1.getstamina();
    k1.checkstam();
    k2.getstamina();
    k2.checkstam();
    hit = k2.didithit();
    mount1 =  k1.checkmount(hit);
    hit = k1.didithit();
    mount2 = k2.checkmount(hit);
    if(mount2 == false)
    {
     k1.printname();
     cout << " knocked ";
     k2.printname();
     cout << " off the horse!" << endl;
    }
    else
    {
    k1.printname();
    cout<< " has missed!" << endl;
    }
    if(mount1 == false)
    {
     k2.printname();
     cout << " knocked ";
     k1.printname();
     cout << " off the horse!" << endl;
    }
    else
    {
     k2.printname();
     cout << " has missed!" << endl;
    }
    k1.display(mount1);
    k2.display(mount2);
    if( mount1 == false || k1.checkstam() == true || mount2 == false || k2.checkstam() == true)
    {
      cout << "One or both of the Knights are no longer capable of jousting. Thank you for playing!" << endl;
      return 0;
    }
    cout << "Are you ready to joust again?(y for yes and n for no)" << endl;
    cin >> play;
  }while(play == 'y');
  return 0;
}  


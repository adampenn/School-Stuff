// Joust Main
#include "Knight.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
        string name1, name2, weapon1, weapon2;
        int hit_chance1, hit_chance2, stam_req1, stam_req2, stamina1, stamina2;
        bool in_progress = true;
        int rounds = 0;

        cout << "The jousting tournament is awaiting you sire." << endl;
        cout << "Please register your name." << endl;
        cin >> name1;
        cout << "Please register your opponent's name sire." << endl;
        cin >> name2;
        cout << "Please choose a weapon for " << name1 << endl;
        cout << "Lance, Sword, Mace." << endl;
        cin >> weapon1;
        cout << "Please choose a weapon for " << name2 << endl;
        cout << "Lance, Sword, or Mace." << endl;
        cin >> weapon2;
        cout << "Specify hit chance for " << weapon1 << endl;
        cin >> hit_chance1;
        cout << "Specify hit chance for " << weapon2 << endl;
        cin >> hit_chance2;
        cout << "Specify stamina required for "<<name1<< "'s weapon" << endl;
        cin >> stam_req1;
        cout << "Specify stamina required for "<<name2<< "'s weapon" << endl;
        cin >> stam_req2;
        cout << "Specify stamina for " << name1 << endl;
        cin >> stamina1;
        cout << "Specify stamina for " << name2 << endl;
        cin >> stamina2;

        cout << "------------------------------------------------------------"<<endl;
        
        Knight k(name1, weapon1, hit_chance1, stam_req1, stamina1);
        Knight k2(name2, weapon2, hit_chance2, stam_req2, stamina2);
        k.display();
        k2.display();
        
        while (in_progress == true)
        {
                if (k.mounted() == false || k2.mounted() == false)
                        in_progress = false;

                else if (k.current_stamina() <= 0 || k2.current_stamina() <= 0)
                        in_progress = false;

                else
                {
                        if (k.did_hit() == true)
                                k2.knockoff();

                        if (k2.did_hit() == true)
                                k.knockoff();
                }
                k.display();
                k2.display();
                rounds++;
                cout << "Rounds: "<<rounds<< " "<<endl;
                
        }		

}

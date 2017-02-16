//Phoebe Desanto 
#include <iostream>
#include <iomanip>
#include "Weapon.cpp"
#include "Knight.cpp"
#include "Random.cpp"
using namespace std;


main () {
    i=1
    string name, weapon_name;
    Knight kn1, kn2;

    cout<<"Welcome welcome to the Grand Jousting Tourny of Albion!"<< endl;
    kn1.display();
    cout<<"Our first Knight is Ulrich Von Liechtenstein!(kn1)"<< endl;
    cout<< "(cheering)"<<endl;
    cout<< "And our second Knight is Sir Not Appearing in This Film(kn2)"<< endl;
     kn2.display();
     cout<< "Who will you choose?(kn1 or kn2)" << endl;
     cin>> Knight

       
       do 
        {
            cout<< "Get Ready for the pass"<<endl;
            if(kn1.attack())
                kn2.unhorse();

            if(kn2.attack())
                kn1.unhorse;           
        kn1.display();
        cout<<""<< endl;
        kn2.display();

        i++
        }while(!kn.!exhausted() && kn1.horse() && !kn2.exhausted() && kn2.onhorse());
     
     }
    

return 0;
}

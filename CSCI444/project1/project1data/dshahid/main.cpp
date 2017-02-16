//Dia Shahid
//Project 4 "Joust"
//CSCI 111

#include"knight.h"
#include"weapon.h"
#include<iostream>
#include<string>
using namespace std;


int main()
{
	//defining variables that we'll be using in the program
  int i=1;
  int kn1Choice, kn2Choice, kn1Wep, kn2Wep;
  //kn1 and kn2 are the knights that we will use for the Jousting
  Knight kn1, kn2;
  //kn3 4 and 5 are used to define the "preset" knights that the user can choose from
  Knight kn3, kn4, kn5;
  //w1 w2 and w3 are Object instances of the Weapon class that we will fill up with stats
  //for the user to pick from ( same logic applies to kn3 kn4 kn5 , except that they
  //are isntances of the Knight class instead )
  Weapon w1,w2,w3;
  //setting the info for the weapons
  w1.set("Rusty Dagger",2,2);
  w2.set("Common Blade",5,3);
  w3.set("Champion's Lance",8,5);
  // setting the info for the knights
  kn3.select("Sir Arthur",25);
  kn4.select("Sir Wimpy",9);
  kn5.select("Sir Lancelot",17);

  cout<<"Welcome to the Grand Master's Jousting match\n\n";
  cout<<"List of knights (Select with 1,2,3)"<<endl;
  // calling the custom made show method which just dispalys the stats of the knights
  kn3.show();
  kn4.show();
  kn5.show();
  cout<<"Select Combatiant #1 : ";
  // taking in the user's choice
  cin >> kn1Choice;
  // using a switch case to handle the user's pick and insert the stats of the chosen
  //knight into the placeholder knight kn1 which will be used for the joust
  switch(kn1Choice)
   {
	case 1 :
      cout << "You have chosen "<<kn3.get_name() << endl<< endl; 
      kn1.set_name(kn3.get_name());
      kn1.set_stamina(kn3.get_stamina());
      break;
	case 2 :
		cout << "You have chosen "<<kn4.get_name()<< endl<< endl;
        kn1.set_name(kn4.get_name());
        kn1.set_stamina(kn4.get_stamina());		
		break;
	case 3 : 
		cout<< "You have chosen "<<kn5.get_name()<<endl<< endl;
        kn1.set_name(kn5.get_name());
        kn1.set_stamina(kn5.get_stamina());		
		break;
	default :
		//in the event that the user inputs something other then 1 ,2 or 3 , termiante the program
		cout<< "Invalid selection, terminating program";
		exit (EXIT_FAILURE);
  }
  cout<<"List of weapons"<<endl;
  w1.display();
  w2.display();
  w3.display();
  cout<<"Choose a weapon for your knight(1,2,3): ";
  // everything here is same as the above for the knights' switch case , except
  // this switch case is used to handle the weapon choice for the first Knight
  cin >> kn1Wep;
  switch(kn1Wep){
  	case 1 :
  		cout<<"You have chosen "<<w1.get_name()<<endl<< endl;
  		kn1.set_weapon_in_hand(w1);
  		break;
  	case 2 :
  		cout<<"You have chosen "<<w2.get_name()<<endl<< endl;
  		kn1.set_weapon_in_hand(w2);
  		break;
  	case 3 :
  		cout<<"You have chosen "<<w3.get_name()<<endl<< endl;
  		kn1.set_weapon_in_hand(w3);
  		break;
  	default:
  		cout<<"Invalid selection, terminating program";
  		exit (EXIT_FAILURE);
  }
  kn1.set_on_Horse(true);
	// the below part is the same as the above , except that it fills in the stats
	// for the second knight instead of the first knight that will be used in the joust
  cout<<"List of knights (Select with 1,2,3)"<<endl;
  kn3.show();
  kn4.show();
  kn5.show();
  cout<<"Select Combatiant #2 : ";
  cin >> kn2Choice;
  switch(kn2Choice)
   {
	case 1 :
      	cout << "You have chosen "<<kn3.get_name() <<endl<<endl; 
      	kn2.set_name(kn3.get_name());
      	kn2.set_stamina(kn3.get_stamina());
      	break;
	case 2 :
		cout << "You have chosen "<<kn4.get_name()<<endl<<endl;
        kn2.set_name(kn4.get_name());
        kn2.set_stamina(kn4.get_stamina());		
		break;
	case 3 : 
		cout<< "You have chosen "<<kn5.get_name()<<endl<<endl;
        kn2.set_name(kn5.get_name());
        kn2.set_stamina(kn5.get_stamina());		
		break;
	default :
		cout<< "Invalid selection, terminating program";
		exit (EXIT_FAILURE);
  }
  cout<<"List of weapons"<<endl;
  w1.display();
  w2.display();
  w3.display();
  cout<<"Choose a weapon for your knight: ";
  cin >> kn2Wep;
  switch(kn2Wep){
  	case 1 :
  		cout<<"You have chosen "<<w1.get_name()<<endl;
  		kn2.set_weapon_in_hand(w1);
  		break;
  	case 2 :
  		cout<<"You have chosen "<<w2.get_name()<<endl;
  		kn2.set_weapon_in_hand(w2);
  		break;
  	case 3 :
  		cout<<"You have chosen "<<w3.get_name()<<endl;
  		kn2.set_weapon_in_hand(w3);
  		break;
  	default:
  		cout<<"Invalid selection, terminating program";
  		exit (EXIT_FAILURE);
  }
  kn2.set_on_Horse(true);
//Joust!
  do
  {
    cout<<"\n\n\nROUND "<<i<<endl;
    
    if(kn1.attack())
      kn2.unhorse();
    if(kn2.attack())
      kn1.unhorse();

    kn1.display();
    cout<<endl<<endl;
    kn2.display();

    i++;
  }while(!kn1.exhausted() && kn1.onhorse() && !kn2.exhausted() && kn2.onhorse());


//followed the stepwise instructions which said
//call display before attack  
  cout<<"\n\n\nFINAL SCORE\nAfter "<<i-1<<" round(s):\n";
  kn1.display();
  cout<<endl<<endl;
  kn2.display();
  cout<<endl;

  return 0;
}


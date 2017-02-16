//File Name: Knight.cpp
//Author: Rod Center
//Date: 12 November 2015
//class definition

#include <iostream>
#include <string>
#include "Weapon.h"
#include "Knight.h"
#include "Random.h"

using namespace std;


//constructor        change varables in initialization list??
  	Knight::Knight(string _Type, int _StaminaCost, int _HitPercent, int _StaminaReserve, string _Name, bool _OnHorse, bool _Exhausted)
      :_MyWeapon(_Type, _StaminaCost, _HitPercent), _StaminaReserve(_StaminaReserve), _Name(_Name), _OnHorse(true), _Exhausted(false)
      {}


    bool Knight::SetOffHorse()

    { 
      _OnHorse = false;
      return _OnHorse;
    }

    bool Knight::GetHorseStatus()
    {
      return _OnHorse;
    }

    int Knight::StaminaMath()
    {
      _StaminaReserve = _StaminaReserve - _MyWeapon.GetCost();

      if (_StaminaReserve<=0)
      {
      	_Exhausted = true;
      }


      return _StaminaReserve;
    }

    void Knight::SetStamina()
    {
      _StaminaReserve=_StaminaReserve;
    }

    int Knight::GetStamina()
    {
      return _StaminaReserve;
    }

    void Knight::SetExhausted(bool &_Exhausted)
    {
      _Exhausted = true;
    }

    bool Knight::GetExhausted()
    {
      return _Exhausted;
    }

    bool Knight::Charge() //returns whether knight hits t/f
    {
     return _MyWeapon.GetHit();
    }

    void Knight::display()
    {
      //Knight statistics
      cout << "\n\n******************************************************\n\n";
      cout <<     "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n";
      cout << "JOUST \n\nMatch Statistics For:\n";
      cout << "Knight Name: "<<_Name<<endl;
      cout << "Stamina Reserve: "<<_StaminaReserve<<endl;
     
      if(_Exhausted == false)
      {
        cout << _Name << " is not exhausted.\n";
      }
      else
      {
        cout << _Name << " is exhausted.\n";
      }

      if (_OnHorse == true)
      {
        cout << _Name <<" is still on his/her horse.\n";
      }
      else
      {
        cout << _Name <<" has been hit, and unhorsed.\n\n";
      }
      _MyWeapon.display();
    cout << "\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    cout << "\n\n******************************************************\n\n";


    }


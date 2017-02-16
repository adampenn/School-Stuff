// File:  Knight.h
// Author: Rod Center
// class declaration


#ifndef KNIGHT_H
#define KNIGHT_H


class Knight {

  private:
  	Weapon _MyWeapon;// instance of weapon class
  	int _StaminaReserve;
  	string _Name;
  	bool _OnHorse;    //set true
    bool _Exhausted; //set false


  public:
    //constructor
    Knight (string _Type, int _StaminaCostint, int _HitPercent, int _StaminaReserve, string _Name, bool _OnHorse, bool _Exhausted);

  	bool SetOffHorse();
    bool GetHorseStatus(); // from main sets knight off horse if opponent hits... pass by reference?
  	int StaminaMath();
  	void SetStamina();
  	int GetStamina();
    void SetExhausted(bool &_Exhausted);
    bool GetExhausted();
    bool Charge();
    void display();


};
#endif

#include"knight.h" 

  knight::knight(string n, int s, string w, int sr, int hc)
: Name(n),
  Stamina(s),
  wc(w,sr,hc),
  OnHorse(true)
{}

void knight::display()
{
  cout << "Knight " << Name << " is using: ";
  wc.displayw();
  if (getStamina() <= 0)
    cout << "Knight " << Name << " is exhausted (Stamina=0)";
  else
    cout << "Knight " << Name << " is not exhausted (Stamina=" << Stamina << ")";

  if (OnHorse)
    cout << "and is still on the horse" << endl;
  else
    cout << "and has been knocked off of the horse" << endl;
}

void knight::unhorsed()
{
  OnHorse = false;
}

bool knight::getDidYouHit()
{
  Stamina = Stamina - wc.getStRq();
  return wc.getHitC();
}

bool knight::GetOffHorse()
{
  if(OnHorse==true)
  {  
    return true;
  } 
  else 
  { 
    return false;
  } 
}

int knight::getStamina()
{ return Stamina;
}


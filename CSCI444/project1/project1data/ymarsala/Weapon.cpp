#include <iostream>
#include <string>
#include "Weapon.h"

using namespace std;

  Weapon::Weapon(string w, int s, int h)
:weapname(w), stamreq(s), hitchance(h)
{
}

int Weapon::stamwrecked()
{
  return stamreq;
}

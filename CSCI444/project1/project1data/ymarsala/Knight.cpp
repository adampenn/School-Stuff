#include <iostream>
#include <string>
#include "Knight.h"
using namespace std;

  Knight::Knight(string n, int s)
:name(n), stam(s)
{
}

void Knight::gettired(int stamreq)
{
  stam= stam - stamreq;
}

int Knight::getstam()
{
  return stam;
}

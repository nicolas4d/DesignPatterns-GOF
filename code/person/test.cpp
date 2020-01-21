#include <iostream>
#include "Person.h"
#include "Person.cpp"

using namespace std;

int main()
{
  Person xc;

  xc.age = 18;
  char liulang[] = "流浪";
  xc.name = liulang;

  char nan[] = "男";
  xc.sex = nan;

  xc.say();
  return 0;
}

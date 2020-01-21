#include <iostream>
#include "Person.h"

using namespace std;

Person::Person()
{
  cout << "创建了一个新的对象！" << endl;
}

void Person::say()
{
  cout << "大家好，我叫" << name << ",性别" << sex << ",今年" << age << "岁." << endl;
}

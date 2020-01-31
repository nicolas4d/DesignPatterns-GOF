#include <iostream>
#include "AbstractList.cpp"
#include "../iterator/Iterator.cpp"
#include "../iterator/ListIterator.cpp"
#include "List.cpp"

using namespace std;

class Test
{
public:
  Test(){}
private:
  int i;
};


int main(int argc, char *argv[])
{
  cout << "main" << "\n" << "\n";

  List<Test*>* lt = new List<Test*>();
  Test* t = new Test();
  lt->Append(t);
  lt->Get(0);

  List<int>* li = new List<int>();
  li->Append(0);
  cout << li->Get(0) << "\n";
  li->Append(1);
  cout << li->Get(1) << "\n";


  // for (int i = 0; i < 20; ++i) {
  //   cout << list1->Get(i) << endl;
  // }

  cout << "\n" << "main end" << "\n";

  return 0;
}

#include <iostream>
#include "View.cpp"
#include "MyView.cpp"

using namespace std;

int main(int argc, char *argv[])
{
  cout << "main" << "\n";

  MyView* mv = new MyView();
  mv->Display();

  cout << "\n" << "end of main" << "\n";

  return 0;
}

#include <iostream>
#include "point.cpp"
#include "view.cpp"
#include "coord.cpp"
#include "window.cpp"

using namespace std;

int main(int argc, char *argv[])
{
  cout << "main" << "\n" << "\n";

  new Point();
  new View();
  new Coord();

  Window* window = new ApplicationWindow(new View());
  window->DrawContents();

  cout << "\n";

  Window* window0 = new IconWindow(new View());
  window0->DrawContents();

  cout  << "\n" << "main end" << "\n";

  return 0;
}

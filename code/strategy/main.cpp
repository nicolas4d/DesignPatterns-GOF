#include <iostream>
#include "Coord.cpp"
#include "Compositor.cpp"
#include "SimpleCompositor.cpp"
#include "TeXCompositor.cpp"
#include "ArrayCompositor.cpp"
#include "Composition.cpp"

using namespace std;

int main(int argc, char *argv[])
{
  cout << "main" << "\n";

  Composition* quick = new Composition(new SimpleCompositor);
  quick->Repair();
  Composition* slick = new Composition(new TeXCompositor);
  slick->Repair();
  Composition* iconic = new Composition(new ArrayCompositor(100));
  iconic->Repair();

  cout << "\n" << "end main" << "\n";

  return 0;
}

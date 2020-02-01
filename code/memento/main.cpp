#include <iostream>
#include "Graphic.cpp"
#include "Point.cpp"
#include "ConstraintSolver.cpp"
#include "MoveCommand.cpp"
#include "ConstraintSolverMemento.cpp"

using namespace std;

int main(int argc, char *argv[])
{
  cout << "main" << "\n" << "\n";

  Graphic* g = new Graphic();
  Point* p = new Point();
  MoveCommand* mc = new MoveCommand(g, *p);
  cout << "\n";
  mc->Execute();
  cout << "\n";
  mc->Unexecute();

  cout << "\n" << "main end" << "\n";

  return 0;
}

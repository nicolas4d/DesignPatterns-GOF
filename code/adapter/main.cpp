#include <iostream>

#include "Coord.cpp"
#include "Point.cpp"
#include "manipulator.cpp"
#include "shape.cpp"
#include "textShape.cpp"
#include "textShape_object.cpp"

using namespace std;

int main(int argc, char *argv[])
{
  cout << "main"<< endl;

  Shape* shape = new TextShape();
  shape->CreateManipulator();

  Shape* shapeOther = new TextShapeObject(new TextView());
  shape->CreateManipulator();

  cout << "main end" << endl;

  return 0;
}


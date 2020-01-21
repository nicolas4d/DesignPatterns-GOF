#ifndef TEXTMANIPULATOR_H
#define TEXTMANIPULATOR_H

#include "manipulator.h"
#include "textShape.h"
#include "textShape_object.cpp"

class TextManipulator:public Manipulator
{
public:
  TextManipulator();
  TextManipulator(const TextShape*);
  TextManipulator(const TextShapeObject*);
};

#endif

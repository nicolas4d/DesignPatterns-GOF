#ifndef SHAPE_H
#define SHAPE_H

#include "manipulator.h"
#include "Point.h"

class Shape
{
 public:
  Shape();
  virtual void BoundingBox(
                           Point& bottomLeft, Point& topRight
                           ) const;

  virtual Manipulator* CreateManipulator() const;
};

#endif

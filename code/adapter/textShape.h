#ifndef TEXTSHAPE_H
#define TEXTSHAPE_H

#include "shape.h"
#include "textView.h"

class TextShape : public Shape, private TextView {
 public:
  TextShape();

  virtual void BoundingBox(
                           Point& bottomLeft, Point& topRight
                           ) const;
  virtual bool IsEmpty() const;
  virtual Manipulator* CreateManipulator() const;
};

#endif

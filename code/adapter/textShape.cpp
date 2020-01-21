#include "textShape.h"
#include "textManipulator.cpp"
#include "textView.cpp"

TextShape::TextShape()
{

}

void TextShape::BoundingBox (
                             Point& bottomLeft, Point& topRight
                             ) const {
  Coord bottom, left, width, height;

  // GetOrigin(bottom, left);
  // GetExtent(width, height);

  // bottomLeft = Point(bottom, left);
  // topRight = Point(bottom + height, left + width);
}

bool TextShape::IsEmpty () const {
  //return TextView::IsEmpty();
  return true;
}

Manipulator* TextShape::CreateManipulator () const {
  return new TextManipulator(this);
}

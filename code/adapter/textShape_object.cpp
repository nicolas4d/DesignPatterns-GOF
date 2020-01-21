#ifndef TEXTSHAPEOBJECT_H
#define TEXTSHAPEOBJECT_H

#include "shape.h"
#include "textView.h"
#include "textManipulator.h"

class TextShapeObject : public Shape {
public:
  TextShapeObject(TextView*);

  virtual void BoundingBox(
                           Point& bottomLeft, Point& topRight
                           ) const;
  virtual bool IsEmpty() const;
  virtual Manipulator* CreateManipulator() const;
private:
  TextView* _text;
};

TextShapeObject::TextShapeObject (TextView* t) {
  _text = t;
}

void TextShapeObject::BoundingBox (
                             Point& bottomLeft, Point& topRight
                             ) const {
  // Coord bottom, left, width, height;
  // _text->GetOrigin(bottom, left);
  // _text->GetExtent(width, height);
  // bottomLeft = Point(bottom, left);
  // topRight = Point(bottom + height, left + width);
}

bool TextShapeObject::IsEmpty () const {
  //return _text->IsEmpty();
  return true;
}

Manipulator* TextShapeObject::CreateManipulator () const {
  //return new TextManipulator(this);
}

#endif

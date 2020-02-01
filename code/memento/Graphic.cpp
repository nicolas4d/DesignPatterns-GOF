#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "Point.cpp"

class Graphic
{
public:
  Graphic();
  void Move(Point);
};

Graphic::Graphic()
{

}

void Graphic::Move(Point p)
{
  std::cout << "void Graphic::Move(Point p)" << "\n";
}

#endif /* GRAPHIC_H */

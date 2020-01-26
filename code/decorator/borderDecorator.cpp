#ifndef BORDERDECORATOR_H
#define BORDERDECORATOR_H

#include "decorator.cpp"

class BorderDecorator : public Decorator {
public:
  BorderDecorator(VisualComponent*, int borderWidth);

  virtual void Draw();
private:
  void DrawBorder(int);
private:
  int _width;
};

BorderDecorator::BorderDecorator(VisualComponent* vc, int borderWidth):Decorator(vc)
{
  std::cout << "BorderDecorator::BorderDecorator(VisualComponent*, int borderWidth)" << "\n";
}

void BorderDecorator::Draw ()
{
  std::cout << "void BorderDecorator::Draw ()" << "\n";

  Decorator::Draw();
  DrawBorder(_width);
}

void BorderDecorator::DrawBorder(int db)
{
  std::cout << "void BorderDecorator::DrawBorder()" << "\n";
}

#endif /* BORDERDECORATOR_H */

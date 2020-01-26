#ifndef SCROLLDECORATOR_H
#define SCROLLDECORATOR_H

#include "decorator.cpp"

class ScrollDecorator : public Decorator {
public:
  ScrollDecorator(VisualComponent*);

  virtual void Draw();
private:
  void DrawScoll();
private:
  int _width;
};

ScrollDecorator::ScrollDecorator(VisualComponent* vc):Decorator(vc)
{
  std::cout << "ScrollDecorator::ScrollDecorator(VisualComponent*)" << "\n";
}

void ScrollDecorator::Draw ()
{
  std::cout << "void ScrollDecorator::Draw ()" << "\n";

  Decorator::Draw();
  DrawScoll();
}

void ScrollDecorator::DrawScoll()
{
  std::cout << "void ScrollDecorator::DrawScoll()" << "\n";
}

#endif /* SCROLLDECORATOR_H */

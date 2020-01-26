#ifndef DECORATOR_H
#define DECORATOR_H

#include "visualComponent.cpp"

class Decorator : public VisualComponent {
public:
  Decorator(VisualComponent*);

  virtual void Draw();
  virtual void Resize();
  // ...
private:
  VisualComponent* _component;
};

Decorator::Decorator(VisualComponent* vc)
{
  std::cout << "Decorator::Decorator(VisualComponent* vc)" << "\n";
  _component = vc;
}

void Decorator::Draw ()
{
  std::cout << "void Decorator::Draw ()" << "\n";
  _component->Draw();
}

void Decorator::Resize ()
{
  std::cout << "void Decorator::Resize ()" << "\n";
  _component->Resize();
}

#endif /* DECORATOR_H */

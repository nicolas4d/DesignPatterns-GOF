#ifndef SIMPLECOMPOSITOR_H
#define SIMPLECOMPOSITOR_H

class Compositor;

class SimpleCompositor : public Compositor {
public:
  SimpleCompositor();

  virtual int Compose(
                      Coord natural[], Coord stretch[], Coord shrink[],
                      int componentCount, int lineWidth, int breaks[]
                      );

  // ...
};

SimpleCompositor::SimpleCompositor()
{
  std::cout << "SimpleCompositor::SimpleCompositor()" << "\n";
}

int SimpleCompositor::Compose(
                    Coord natural[], Coord stretch[], Coord shrink[],
                    int componentCount, int lineWidth, int breaks[]
                              )
{
  std::cout << "int SimpleCompositor::Compose" << "\n";
}

#endif /* SIMPLECOMPOSITOR_H */

#ifndef ARRAYCOMPOSITOR_H
#define ARRAYCOMPOSITOR_H

class ArrayCompositor : public Compositor {
public:
  ArrayCompositor(int interval);

  virtual int Compose(
                      Coord natural[], Coord stretch[], Coord shrink[],
                      int componentCount, int lineWidth, int breaks[]
                      );
  // ...
};

ArrayCompositor::ArrayCompositor(int interval)
{
  std::cout << "ArrayCompositor::ArrayCompositor(int interval)" << "\n";
}

int ArrayCompositor::Compose(
                    Coord natural[], Coord stretch[], Coord shrink[],
                    int componentCount, int lineWidth, int breaks[]
                             )
{
  std::cout << "int ArrayCompositor::Compose" << "\n";
}

#endif /* ARRAYCOMPOSITOR_H */

#ifndef TEXCOMPOSITOR_H
#define TEXCOMPOSITOR_H

class TeXCompositor : public Compositor {
public:
  TeXCompositor();

  virtual int Compose(
                      Coord natural[], Coord stretch[], Coord shrink[],
                      int componentCount, int lineWidth, int breaks[]
                      );
  // ...
};

TeXCompositor::TeXCompositor()
{
  std::cout << "TeXCompositor::TeXCompositor()" << "\n";
}

int TeXCompositor::Compose(
                    Coord natural[], Coord stretch[], Coord shrink[],
                    int componentCount, int lineWidth, int breaks[]
                           )
{
  std::cout << "int TeXCompositor::Compose" << "\n";
}

#endif /* TEXCOMPOSITOR_H */

#ifndef COMPOSITION_H
#define COMPOSITION_H

class Compositor;
class Component;
class Coord;

class Composition {
public:
  Composition(Compositor*);
  void Repair();

private:
  Compositor* _compositor;
  Component* _components;  // the list of components
  int _componentCount; // the number of components
  int _lineWidth; // the Composition's line width
  int* _lineBreaks;  // the position of linebreaks
  // in components
  int _lineCount;   // the number of lines
};

Composition::Composition(Compositor* c)
{
  _compositor = c;
}

void Composition::Repair () {
  Coord* natural;
  Coord* stretchability;
  Coord* shrinkability;
  int componentCount;
  int* breaks;

  // prepare the arrays with the desired component sizes
  // ...

  // determine where the breaks are:
  int breakCount;
  breakCount = _compositor->Compose(
                                    natural, stretchability, shrinkability,
                                    componentCount, _lineWidth, breaks
                                    );
  
  // lay out components according to breaks
  // ...
}

#endif /* COMPOSITION_H */

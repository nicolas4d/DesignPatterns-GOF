#ifndef CABINET_H
#define CABINET_H

#include "compositeEquipment.cpp"

class Cabinte : public CompositeEquipment
{
public:
  Cabinte(const char*);
};

Cabinte::Cabinte(const char* name):CompositeEquipment(name)
{
  std::cout << "Cabinet::Cabinet(const char*)" << "\n";
}

#endif /* CABINET_H */

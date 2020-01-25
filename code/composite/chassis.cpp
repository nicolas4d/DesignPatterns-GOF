#ifndef CHASSIS_H
#define CHASSIS_H

#include "compositeEquipment.cpp"

class Chassis : public CompositeEquipment {
public:
  Chassis(const char*);
  //virtual ~Chassis();

  // virtual Watt Power();
  // virtual Currency NetPrice();
  // virtual Currency DiscountPrice();
};

Chassis::Chassis(const char* name):CompositeEquipment(name)
{
  std::cout << "Chassis::Chassis(const char*)" << "\n";
}

#endif /* CHASSIS_H */

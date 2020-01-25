#ifndef COMPOSITEEQUIPMENT_H
#define COMPOSITEEQUIPMENT_H

#include "equipment.cpp"
#include <list>

using namespace std;

typedef list<Equipment> List;

class CompositeEquipment : public Equipment {
public:
  //virtual Watt Power();
  //virtual Currency NetPrice();
  //virtual Currency DiscountPrice();
  virtual void Add(Equipment*);
  //virtual void Remove(Equipment*);
  //virtual Iterator* CreateIterator();

  virtual void sum();

protected:
  CompositeEquipment(const char*);

private:
  List _equipment;
};

CompositeEquipment::CompositeEquipment(const char* name):Equipment(name)
{
  cout << "CompositeEquipment::CompositeEquipment(const char*)" << "\n";
}

void CompositeEquipment::sum ()
{
  std::cout << "void CompositeEquipment::sum ()" << "\n";

  int size = _equipment.size();
  cout << size << "\n";
}

void CompositeEquipment::Add(Equipment* e)
{
  std::cout << "virtual void Add(Equipment*)" << "\n";

  _equipment.push_back(*e);
}


// Currency CompositeEquipment::NetPrice () {
//   Iterator* i = CreateIterator();
//   Currency total = 0;

//   for (i->First(); !i->IsDone(); i->Next()) {
//     total += i->CurrentItem()->NetPrice();
//   }

//   delete i;

//   return total;
// }

#endif /* COMPOSITEEQUIPMENT_H */

#ifndef EQUIPMENT_H
#define EQUIPMENT_H

class Equipment {
public:
  //virtual ~Equipment();

  const char* Name() { return _name; }

  //virtual Watt Power();
  //virtual Currency NetPrice();
  //virtual Currency DiscountPrice();
  virtual void Add(Equipment*);
  virtual void Remove(Equipment*);
  //virtual Iterator* CreateIterator();

protected:
  Equipment(const char*);

private:
  const char* _name;
};

Equipment::Equipment(const char* name)
{
  std::cout << "Equipment::Equipment(const char*)" << "\n";

  _name = name;
}

void Equipment::Add(Equipment*)
{
  std::cout << "virtual void Add(Equipment*)" << "\n";
}

void Equipment::Remove(Equipment*)
{
  std::cout << "virtual void Remove(Equipment*)" << "\n";
}

#endif /* EQUIPMENT_H */

#include <iostream>
#include "equipment.cpp"
#include "compositeEquipment.cpp"
#include "chassis.cpp"
#include "cabinet.cpp"

using namespace std;

int main(int argc, char *argv[])
{
  cout << "main" << "\n"  << "\n";

  Equipment* e;
  CompositeEquipment* ce;

  const char* str = "hello";    //指针方式
  Chassis* chasis = new Chassis(str);
  Cabinte* cabinte = new Cabinte(str);
  cabinte->Add(chasis);
  cabinte->sum();


  // Cabinet* cabinet = new Cabinet("PC Cabinet");
  // Chassis* chassis = new Chassis("PC Chassis");

  // cabinet->Add(chassis);

  // Bus* bus = new Bus("MCA Bus");
  // bus->Add(new Card("16Mbs Token Ring"));
  // chassis->Add(bus);
  // chassis->Add(new FloppyDisk("3.5in Floppy"));
  // cout << "The net price is " << chassis->NetPrice() << endl;

  cout <<"\n" << "main end" << "\n";
  return 0;
}

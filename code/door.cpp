#include "door.h" 

Door::Door (Room* room1, Room* room2) {
  _room1 = room1;
  _room2 = room2;

  cout << "Door::Door" << endl;
}

void Door::Initialize (Room* r1, Room* r2) {
  _room1 = r1;
  _room2 = r2;

  cout << "Door::Initialize" << endl;
}

Door* Door::Clone () const {
  cout << "Door::Clone " << endl;
  return new Door(*this);
}

void Door::Enter()
{
  cout << "Door::Enter " << endl;
}

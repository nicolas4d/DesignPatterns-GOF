#include "room.h"

Room::Room()
{
  cout << "Room::Room" << endl;
}

void Room::Initialize(int roomNo)
{
  _roomNumber = roomNo;

  cout << "Room::Initialize " << endl;
}

Room* Room::Clone() const
{
  return new Room(*this);

  cout << "Room::Clone " << endl;
}

Room::Room(int roomNo)
{
  cout << "Room::Room " <<  "roomNo =" << roomNo <<  "\n";

  _roomNumber = roomNo;
}



RoomWithABomb::RoomWithABomb(int n):Room(n)
{
  cout << "RoomWithABomb::RoomWithABomb " << "\n";
}

MapSite* Room::GetSide(Direction dire) const
{
  cout << "Room::GetSide" << "\n";

  return _sides[dire];
}

void Room::SetSide(Direction dire, MapSite* mapSite)
{
  cout << "Room::SetSide" << "Direction = " << dire << "\n";

  _sides[dire] = mapSite;
}

void Room:: Enter()
{
  cout << "Room::Enter" << "\n";
}

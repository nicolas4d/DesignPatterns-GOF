#ifndef ROOM_H
#define ROOM_H

#include "mapSite.h"

enum Direction
  {
   North,
   South,
   West,
   East
  };


class Room : public MapSite {
 public:
  Room();
  Room(int roomNo);

  virtual void Initialize(int);
  virtual Room* Clone() const;

  MapSite* GetSide(Direction) const;
  void SetSide(Direction, MapSite*);
  virtual void Enter();
 private:
  MapSite* _sides[4];
  int _roomNumber;
};

class RoomWithABomb : public Room
{
 public:
  RoomWithABomb(){}
  RoomWithABomb(int);
};

#endif

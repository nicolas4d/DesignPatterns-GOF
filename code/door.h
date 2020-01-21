#ifndef DOOR_H
#define DOOR_H

#include "mapSite.h"

class Door : public MapSite {
 public:
  Door(){}
  Door(Room*, Room*);

  virtual void Initialize(Room*, Room*);
  virtual Door* Clone() const;

  virtual void Enter();
  Room* OtherSideFrom(Room*);
 private:
  Room* _room1;
  Room* _room2;
};

#endif

#ifndef PERSON_H
#define PERSON_H

#include "room.h"

class Maze {
 public:
  Maze();

  virtual void Initialize();
  virtual Maze* Clone() const;

  void AddRoom(Room*);
  Room* RoomNo(int) const;

 private:
  int mazeint; // no meaning
};

#endif

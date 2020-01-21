#ifndef SINGLETOM_MAZEFACTORY_H
#define SINGLETOM_MAZEFACTORY_H

#include "room.h"
#include "maze.h"
#include "wall.h"
#include "door.h"

class MazeFactory {
 public:
  static MazeFactory* Instance();

  // existing interface goes here
  virtual Maze* MakeMaze() const
  { return new Maze; }

  virtual Wall* MakeWall() const
  { return new Wall; }

  virtual Room* MakeRoom(int n) const
  { return new Room(n); }

  virtual Door* MakeDoor(Room* r1, Room* r2) const
  { return new Door(r1, r2); }

 protected:
  MazeFactory();

 private:
  static MazeFactory* _instance;
};

#endif

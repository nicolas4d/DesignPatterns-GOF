#ifndef SINGLETON_MAZEGAME_H
#define SINGLETON_MAZEGAME_H

class MazeGame
{
 public:
  MazeGame();

  virtual Maze* CreateMaze(MazeFactory&);
};

#endif

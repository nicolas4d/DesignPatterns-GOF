#include <iostream>
#include "singleton_MazeFactory.cpp"
#include "maze.cpp"
#include "wall.cpp"
#include "room.cpp"
#include "door.cpp"
#include "singleton_mazeGame.cpp"

using namespace std;

int main(int argc, char *argv[])
{
  MazeGame* mg = new MazeGame();
  MazeFactory* mf = MazeFactory::Instance();
  mg->CreateMaze(*mf);

  return 0;
}

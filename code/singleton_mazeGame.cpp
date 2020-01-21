#include "singleton_mazeGame.h"

MazeGame::MazeGame()
{
  cout << "MazeGame::MazeGame" << "\n";
}

Maze* MazeGame::CreateMaze (MazeFactory& factory) {
  cout << "MazeGame::CreateMaze " << endl;

  Maze* aMaze = factory.MakeMaze();
  Room* r1 = factory.MakeRoom(1);
  Room* r2 = factory.MakeRoom(2);
  Door* aDoor = factory.MakeDoor(r1, r2);

  aMaze->AddRoom(r1);
  aMaze->AddRoom(r2);

  r1->SetSide(North, factory.MakeWall());
  r1->SetSide(South, factory.MakeWall());
  r1->SetSide(West, factory.MakeWall());
  r1->SetSide(East, aDoor);

  r2->SetSide(North, factory.MakeWall());
  r2->SetSide(South, factory.MakeWall());
  r2->SetSide(West, aDoor);
  r2->SetSide(East, factory.MakeWall());

  return aMaze;
}


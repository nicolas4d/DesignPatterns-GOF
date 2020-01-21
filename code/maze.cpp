#include "maze.h"

void Maze::Initialize()
{
  cout << "Maze::Initialize " << endl;
}

Maze* Maze::Clone() const
{
  cout << "Maze::Clone " << endl;

  return new Maze(*this);
}

Maze::Maze()
{
  cout << "Maze::Maze" << "\n";
}

void Maze::AddRoom(Room*)
{
  cout << "Maze::AddRoom" << "\n";
}

Room* Maze::RoomNo(int roomNo) const
{
  cout << "Maze::RoomNo" << "\n";
}


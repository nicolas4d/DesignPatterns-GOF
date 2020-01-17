#include <iostream>
using namespace std;

enum Direction
  {
   North,
   South,
   West,
   East
  };

class MapSite {
public:
  virtual void Enter() = 0;
};

class Room : public MapSite {
public:
  Room(int roomNo);
  MapSite* GetSide(Direction) const;
  void SetSide(Direction, MapSite*);
  virtual void Enter();
private:
  MapSite* _sides[4];
  int _roomNumber;
};

Room::Room(int roomNo)
{
  cout << "Room::Room " <<  "roomNo =" << roomNo <<  "\n";

  _roomNumber = roomNo;
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

class Wall : public MapSite {
public:
  Wall();
  virtual void Enter();
};

Wall::Wall()
{
  cout << "Wall::Wall" << "\n";
}

void Wall::Enter()
{
  cout << "Wall::Enter" << "\n";
}

class Door : public MapSite {
public:
  Door(Room* = 0, Room* = 0);

  virtual void Enter();
  Room* OtherSideFrom(Room*);

private:
  Room* _room1;
  Room* _room2;
  bool _isOpen;
};

Door::Door(Room* r1, Room* r2)
{
  cout << "Door::Door " << " r1 = " << r1 << " r2 = " << r2 << "\n";

  _room1 = r1;
  _room2 = r2;
}

void Door::Enter()
{
  cout << "Door::Enter" << "\n";
}

Room* Door::OtherSideFrom(Room* room)
{
  cout << "Door::OtherSideFrom" << "\n";
}

class Maze {
public:
  Maze();

  void AddRoom(Room*);
  Room* RoomNo(int) const;

private:
  int mazeint; // no meaning
};

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

class MazeGame
{
public:
  MazeGame();

  virtual Maze* CreateMaze();
};

MazeGame::MazeGame()
{
  cout << "MazeGame::MazeGame" << "\n";
}

Maze* MazeGame::CreateMaze () {
  Maze* aMaze = new Maze;
  Room* r1 = new Room(1);
  Room* r2 = new Room(2);
  Door* theDoor = new Door(r1, r2);

  aMaze->AddRoom(r1);
  aMaze->AddRoom(r2);

  r1->SetSide(North, new Wall);
  r1->SetSide(South, new Wall);
  r1->SetSide(West, new Wall);
  r1->SetSide(East, theDoor);

  r2->SetSide(North, new Wall);
  r2->SetSide(South, new Wall);
  r2->SetSide(West, theDoor);
  r2->SetSide(East, new Wall);

  return aMaze;
}

int main(int argc, char *argv[])
{
  cout << "main" << "\n" ;

  MazeGame* mazeGame = new MazeGame();
  mazeGame->CreateMaze();

  cout << "end of main" << "\n";

  return 0;
}

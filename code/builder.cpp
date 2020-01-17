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
  cout << "Room::SetSide " << "Direction = " << dire << "\n";

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

class MazeBuilder {
public:
  virtual void BuildMaze() { }
  virtual void BuildRoom(int room) { }
  virtual void BuildDoor(int roomFrom, int roomTo) { }

  virtual Maze* GetMaze() { return 0; }
protected:
  MazeBuilder();
};

MazeBuilder::MazeBuilder()
{
  cout << "MazeBuilder " << "\n";
}

class StandardMazeBuilder : public MazeBuilder {
public:
  StandardMazeBuilder();

  virtual void BuildMaze();
  virtual void BuildRoom(int);
  virtual void BuildDoor(int, int);

  virtual Maze* GetMaze();
private:
  //CommonWall is a utility operation that determines the direction of the
  //common wall between two rooms.
  Direction CommonWall(Room*, Room*);
  Maze* _currentMaze;
};

StandardMazeBuilder::StandardMazeBuilder ()
{
  _currentMaze = 0;
}

void StandardMazeBuilder::BuildMaze () {
  _currentMaze = new Maze;
}

Maze* StandardMazeBuilder::GetMaze () {
  return _currentMaze;
}

void StandardMazeBuilder::BuildRoom (int n)
{
  if (!_currentMaze->RoomNo(n)) {
    Room* room = new Room(n);
    _currentMaze->AddRoom(room);

    room->SetSide(North, new Wall);
    room->SetSide(South, new Wall);
    room->SetSide(East, new Wall);
    room->SetSide(West, new Wall);
  }
}

Direction StandardMazeBuilder::CommonWall(Room*, Room*)
{
  cout << "StandardMazeBuilder::CommonWall " << "\n";

  return North;
}

void StandardMazeBuilder::BuildDoor (int n1, int n2) {
  Room* r1 = _currentMaze->RoomNo(n1);
  Room* r2 = _currentMaze->RoomNo(n2);
  Door* d = new Door(r1, r2);

  r1->SetSide(CommonWall(r1,r2), d);
  r2->SetSide(CommonWall(r2,r1), d);
}

class CountingMazeBuilder : public MazeBuilder
{
public:
  CountingMazeBuilder();

  // virtual void BuildMaze();
  virtual void BuildRoom(int);
  virtual void BuildDoor(int, int);
  //virtual void AddWall(int, Direction);

  virtual void GetCounts(int&, int&) const;
private:
  int _doors;
  int _rooms;
};

CountingMazeBuilder::CountingMazeBuilder ()
{
  //_rooms = _doors = 0;
}

void CountingMazeBuilder::BuildRoom (int) {
  _rooms++;
}

void CountingMazeBuilder::BuildDoor (int, int) {
  _doors++;
}

void CountingMazeBuilder::GetCounts (int& rooms, int& doors) const
{
  rooms = _rooms;
  doors = _doors;
}

class MazeGame
{
public:
  MazeGame();

  virtual Maze* CreateMaze(MazeBuilder&);
  virtual Maze* CreateComplexMaze(MazeBuilder&);
};

MazeGame::MazeGame()
{
  cout << "MazeGame::MazeGame" << "\n";
}

Maze* MazeGame::CreateMaze (MazeBuilder& builder) {
  builder.BuildMaze();

  builder.BuildRoom(1);
  builder.BuildRoom(2);
  builder.BuildDoor(1, 2);

  return builder.GetMaze();
}

Maze* MazeGame::CreateComplexMaze (MazeBuilder& builder) {
  builder.BuildRoom(1);
  // ...
  builder.BuildRoom(1001);
  return builder.GetMaze();
}

int main(int argc, char *argv[])
{
  cout << "main" << "\n" ;

  Maze* maze;
  MazeGame game;
  StandardMazeBuilder builder;

  game.CreateMaze(builder);
  maze = builder.GetMaze();

  cout << "\n\n\n\n";

  int rooms, doors;
  MazeGame newGame;
  CountingMazeBuilder CMBuilder;

  newGame.CreateMaze(CMBuilder);
  CMBuilder.GetCounts(rooms, doors);

  cout << "The maze has "
       << rooms << " rooms and "
       << doors << " doors" << endl;

  cout << "end of main" << "\n";

  return 0;
}

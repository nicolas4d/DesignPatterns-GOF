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

class RoomWithABomb : public Room
{
public:
  RoomWithABomb(int);
};

RoomWithABomb::RoomWithABomb(int n):Room(n)
{
  cout << "RoomWithABomb::RoomWithABomb " << "\n";
}

class Spell
{
public:
  Spell();
};

Spell::Spell()
{
  cout << "Spell::Spell " << "\n";
}

class EnchantedRoom : public Room
{
public:
  EnchantedRoom(int, Spell*);
};

EnchantedRoom::EnchantedRoom(int n, Spell* cs):Room(n)
{
  cout << "EnchantedRoom " << "\n";
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

class BombedWall : public Wall
{
public:
  BombedWall();
};

BombedWall::BombedWall()
{
  cout << "BombedWall::BombedWall " << "\n";
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

class DoorNeedingSpell : public Door
{
public:
  DoorNeedingSpell(Room*, Room*);
};

DoorNeedingSpell::DoorNeedingSpell(Room* r1, Room* r2):Door(r1, r2)
{
  cout << "DoorNeedingSpell::DoorNeedingSpell " << "\n";
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

class MazeGame {
public:
  Maze* CreateMaze();

  // factory methods:
  virtual Maze* MakeMaze() const
  { return new Maze; }

  virtual Room* MakeRoom(int n) const
  { return new Room(n); }

  virtual Wall* MakeWall() const
  { return new Wall; }

  virtual Door* MakeDoor(Room* r1, Room* r2) const
  { return new Door(r1, r2); }
};

Maze* MazeGame::CreateMaze () {
  Maze* aMaze = MakeMaze();

  Room* r1 = MakeRoom(1);
  Room* r2 = MakeRoom(2);
  Door* theDoor = MakeDoor(r1, r2);

  aMaze->AddRoom(r1);
  aMaze->AddRoom(r2);

  r1->SetSide(North, MakeWall());
  r1->SetSide(East, theDoor);
  r1->SetSide(South, MakeWall());
  r1->SetSide(West, MakeWall());

  r2->SetSide(North, MakeWall());
  r2->SetSide(East, MakeWall());
  r2->SetSide(South, MakeWall());
  r2->SetSide(West, theDoor);

  return aMaze;
}

class BombedMazeGame : public MazeGame {
public:
  BombedMazeGame();

  virtual Wall* MakeWall() const
  { return new BombedWall; }

  virtual Room* MakeRoom(int n) const
  { return new RoomWithABomb(n); }
};

BombedMazeGame::BombedMazeGame()
{
  cout << "BombedMazeGame::BombedMazeGame " << "\n";
}

class EnchantedMazeGame : public MazeGame {
public:
  EnchantedMazeGame();

  virtual Room* MakeRoom(int n) const
  { return new EnchantedRoom(n, CastSpell()); }

  virtual Door* MakeDoor(Room* r1, Room* r2) const
  { return new DoorNeedingSpell(r1, r2); }

protected:
  Spell* CastSpell() const;
};

EnchantedMazeGame::EnchantedMazeGame()
{
  cout << "EnchantedMazeGame::EnchantedMazeGame " << "\n";
}

Spell* EnchantedMazeGame::CastSpell() const
{
  cout << "EnchantedMazeGame::CastSpell " << "\n";
}

int main(int argc, char *argv[])
{
  cout << "main" << endl << endl;

  MazeGame* mazeGame = new MazeGame();
  mazeGame->CreateMaze();

  cout << endl;

  BombedMazeGame* bmg = new BombedMazeGame();
  bmg->CreateMaze();

  cout << endl;

  EnchantedMazeGame* emg = new EnchantedMazeGame();
  emg->CreateMaze();

  cout << "end of main" << endl << endl;

  return 0;
}

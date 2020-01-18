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
  Room();
  Room(int roomNo);

  virtual void Initialize(int);
  virtual Room* Clone() const;

  MapSite* GetSide(Direction) const;
  void SetSide(Direction, MapSite*);
  virtual void Enter();
private:
  MapSite* _sides[4];
  int _roomNumber;
};

Room::Room()
{
  cout << "Room::Room" << endl;
}

void Room::Initialize(int roomNo)
{
  _roomNumber = roomNo;

  cout << "Room::Initialize " << endl;
}

Room* Room::Clone() const
{
  return new Room(*this);

  cout << "Room::Clone " << endl;
}

Room::Room(int roomNo)
{
  cout << "Room::Room " <<  "roomNo =" << roomNo <<  "\n";

  _roomNumber = roomNo;
}

class RoomWithABomb : public Room
{
public:
  RoomWithABomb(){}
  RoomWithABomb(int);
};

RoomWithABomb::RoomWithABomb(int n):Room(n)
{
  cout << "RoomWithABomb::RoomWithABomb " << "\n";
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

Door::Door (Room* room1, Room* room2) {
  _room1 = room1;
  _room2 = room2;

  cout << "Door::Door" << endl;
}

void Door::Initialize (Room* r1, Room* r2) {
  _room1 = r1;
  _room2 = r2;

  cout << "Door::Initialize" << endl;
}

Door* Door::Clone () const {
  cout << "Door::Clone " << endl;
  return new Door(*this);
}

void Door::Enter()
{
  cout << "Door::Enter " << endl;
}

class Wall : public MapSite {
public:
  Wall();

  virtual void Initialize();
  virtual Wall* Clone() const;

  virtual void Enter();
};

Wall::Wall()
{
  cout << "Wall::Wall" << "\n";
}

void Wall::Initialize()
{
  cout << "Wall::Initialize " << endl;
}

Wall* Wall::Clone() const
{
  cout << "Wall::Clone " << endl;

  return new Wall(*this);
}

void Wall::Enter()
{
  cout << "Wall::Enter" << "\n";

}

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

class BombedWall : public Wall {
public:
  BombedWall(){}
  BombedWall(const BombedWall&);

  virtual Wall* Clone() const;
  bool HasBomb();
private:
  bool _bomb;
};

BombedWall::BombedWall (const BombedWall& other) : Wall(other) {
  cout << "BombedWall::BombedWall " << endl;

  _bomb = other._bomb;
}

Wall* BombedWall::Clone () const {
  cout << "BombedWall::Clone " << endl;
  return new BombedWall(*this);
}

class MazeFactory {
public:
  MazeFactory();

  virtual Maze* MakeMaze() const
  { return new Maze; }

  virtual Wall* MakeWall() const
  { return new Wall; }

  virtual Room* MakeRoom(int n) const
  { return new Room(n); }

  virtual Door* MakeDoor(Room* r1, Room* r2) const
  { return new Door(r1, r2); }
};

MazeFactory::MazeFactory()
{
  cout << "MazeFactory::MazeFactory " << "\n";
}

class MazePrototypeFactory : public MazeFactory {
public:
  MazePrototypeFactory(Maze*, Wall*, Room*, Door*);

  virtual Maze* MakeMaze() const;
  virtual Room* MakeRoom(int) const;
  virtual Wall* MakeWall() const;
  virtual Door* MakeDoor(Room*, Room*) const;

private:
  Maze* _prototypeMaze;
  Room* _prototypeRoom;
  Wall* _prototypeWall;
  Door* _prototypeDoor;
};

MazePrototypeFactory::MazePrototypeFactory (
                                            Maze* m, Wall* w, Room* r, Door* d
                                            ) {
  _prototypeMaze = m;
  _prototypeWall = w;
  _prototypeRoom = r;
  _prototypeDoor = d;

  cout << "MazePrototypeFactory::MazePrototypeFactory " << endl;
}

Maze* MazePrototypeFactory::MakeMaze() const
{
  cout << "MazePrototypeFactory::MakeMaze " << endl;

  return _prototypeMaze->Clone();
}

Room* MazePrototypeFactory::MakeRoom(int roomNo) const
{
  cout << "MazePrototypeFactory::MakeRoom" << endl;

  return _prototypeRoom->Clone();
}

Wall* MazePrototypeFactory::MakeWall () const {
  cout << "MazePrototypeFactory::MakeWall " << endl;

  return _prototypeWall->Clone();
}

Door* MazePrototypeFactory::MakeDoor (Room* r1, Room *r2) const {
  cout << "MazePrototypeFactory::MakeDoor " << endl;

  Door* door = _prototypeDoor->Clone();
  door->Initialize(r1, r2);
  return door;
}

class MazeGame
{
public:
  MazeGame();

  virtual Maze* CreateMaze(MazeFactory&);
};

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

int main(int argc, char *argv[])
{
  cout << "main" << "\n" ;

  MazeGame game;
  MazePrototypeFactory simpleMazeFactory(
                                         new Maze, new Wall, new Room, new Door
                                         );
  Maze* maze = game.CreateMaze(simpleMazeFactory);

  cout << endl;

  MazePrototypeFactory bombedMazeFactory(
                                         new Maze, new BombedWall,
                                         new RoomWithABomb, new Door
                                         );
  maze = game.CreateMaze(bombedMazeFactory);

  cout << "end of main" << "\n";

  return 0;
}

class CountingMazeBuilder
{
public:
  CountingMazeBuilder();

  //virtual void BuildMaze();
  virtual void BuildRoom(int);
  virtual void BuildDoor(int, int);

  virtual void GetCounts(int&, int&) const;
private:
  int _doors;
  int _rooms;
};

CountingMazeBuilder::CountingMazeBuilder ()
{
  _rooms = _doors = 0;
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

int main(int argc, char *argv[])
{
  
  return 0;
}

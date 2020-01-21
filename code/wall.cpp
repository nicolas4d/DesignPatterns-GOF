#include "wall.h"

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

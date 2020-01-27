#ifndef POINT_H
#define POINT_H

using namespace std;

class Point
{
public:
  Point();
  Point(int x, int y);
  virtual void operator=(Point*);
  virtual bool operator==(Point*);
  friend istream & operator >> (istream &, Point &);
  friend ostream & operator << (ostream &, Point &);

  const static int Zero = 0;
  int x;
  int y;
};


Point::Point()
{
  x = 0;
  y = 0;
}

Point::Point(int x, int y)
{
  this->x = x;
  this->y = y;
}

void Point::operator=(Point* p)
{
  this->x = p->x;
  this->y = p->y;
}

bool Point::operator==(Point* p)
{
  if (this->x == p->x and this->y == p->y) {
    return true;
  }
  else {
    return false;
  }
}

istream & operator >> (istream& i, Point& p)
{
  i >> p.x >> p.y;
  return i;
}

ostream & operator << (ostream & o, Point & p)
{
  o << "(" << p.x << "+" << p.y << ")" << endl;
  return o;
}

#endif /* POINT_H */

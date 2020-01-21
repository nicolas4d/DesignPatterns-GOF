#ifndef POINT_H
#define POINT_H

class Point
{
 public:
  Point();
  Point(int, int);
  Point(Coord&, Coord&);

private:
  int _x;
  int _y;
};

#endif

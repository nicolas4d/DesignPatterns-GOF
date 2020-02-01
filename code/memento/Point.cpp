#ifndef POINT_H
#define POINT_H

class Point
{
public:
  Point();
  friend Point operator-(const Point&, const Point&);
  Point operator-();
};

Point::Point()
{
  
}

Point operator-(const Point& p1, const Point& p2)
{
  return p1;
}

Point Point::operator-()
{
  
}

#endif /* POINT_H */

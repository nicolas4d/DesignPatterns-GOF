#ifndef WINDOWIMP_H
#define WINDOWIMP_H

#include "window.cpp"
#include "point.cpp"
#include "coord.cpp"
#include <iostream>

using namespace std;

class WindowImp {
public:
  // virtual void ImpTop() = 0;
  // virtual void ImpBottom() = 0;
  // virtual void ImpSetExtent(const Point&) = 0;
  // virtual void ImpSetOrigin(const Point&) = 0;
  virtual void DeviceRect(Coord, Coord, Coord, Coord) = 0;
  // virtual void DeviceText(const char*, Coord, Coord) = 0;
  // virtual void DeviceBitmap(const char*, Coord, Coord) = 0;
  // lots more functions for drawing on windows...

protected:
  WindowImp();
};

class XWindowImp : public WindowImp {
public:
  XWindowImp();

  virtual void DeviceRect(Coord, Coord, Coord, Coord);
  // remainder of public interface...
private:
  // lots of X window system-specific state, including:
  //Display* _dpy;
  //Drawable _winid;

  // window id
  //GC _gc;
  // window graphic context
};

class PMWindowImp : public WindowImp {
public:
  PMWindowImp();

  virtual void DeviceRect(Coord, Coord, Coord, Coord);
  // remainder of public interface...

private:
  // lots of PM window system-specific state, including:
  //HPS _hps;
};

WindowImp::WindowImp()
{
  cout << "WindowImp::WindowImp" << "\n";
}

XWindowImp::XWindowImp()
{
  cout << "XWindowImp::XWindowImp()" << "\n";
}

void XWindowImp::DeviceRect (
                             Coord x0, Coord y0, Coord x1, Coord y1
                             ) {
  cout << "void XWindowImp::DeviceRect" << "\n";

  // int x = round(min(x0, x1));
  // int y = round(min(y0, y1));
  // int w = round(abs(x0 - x1));
  // int h = round(abs(y0 - y1));
  // XDrawRectangle(_dpy, _winid, _gc, x, y, w, h);
}

PMWindowImp::PMWindowImp()
{
  cout << "PMWindowImp::PMWindowImp()" << "\n";
}

void PMWindowImp::DeviceRect (
                              Coord x0, Coord y0, Coord x1, Coord y1
                              ) {
  cout << "void PMWindowImp::DeviceRect (" << "\n";

  // Coord left = min(x0, x1);
  // Coord right = max(x0, x1);
  // Coord bottom = min(y0, y1);
  // Coord top = max(y0, y1);

  // PPOINTL point[4];
  // point[0].x = left;
  // point[0].y = top;
  // point[1].x = right;
  // point[1].y = top;
  // point[2].x = right; point[2].y = bottom;
  // point[3].x = left; point[3].y = bottom;

  // if (
  //     (GpiBeginPath(_hps, 1L) == false) ||
  //     (GpiSetCurrentPosition(_hps, &point[3]) == false) ||
  //     (GpiPolyLine(_hps, 4L, point) == GPI_ERROR) ||
  //     (GpiEndPath(_hps) == false)
  //     ) {
  //   // report error
  // } else {
  //   GpiStrokePath(_hps, 1L, 0L);
  // }
}

#endif /* WINDOWIMP_H */



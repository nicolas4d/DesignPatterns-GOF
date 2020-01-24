#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include "point.cpp"
#include "view.cpp"
#include "windowImp.cpp"

using namespace std;

class Window {
public:
  Window(View* contents);

  // requests handled by window
  virtual void DrawContents();
  // virtual void Open();
  // virtual void Close();
  // virtual void Iconify();
  // virtual void Deiconify();

  // requests forwarded to implementation
  virtual void SetOrigin(const Point& at);
  // virtual void SetExtent(const Point& extent);
  // virtual void Raise();
  // virtual void Lower();
  // virtual void DrawLine(const Point&, const Point&);
  virtual void DrawRect(const Point&, const Point&);
  // virtual void DrawPolygon(const Point[], int n);
  // virtual void DrawText(const char*, const Point&);

protected:
  WindowImp* GetWindowImp();
  View* GetView();

private:
  WindowImp* _imp;
  View* _contents; // the window's contents
};

class ApplicationWindow : public Window
{
public:
  ApplicationWindow(View* contents);
  // ...
  virtual void DrawContents();
};

class IconWindow : public Window
{
public:
  IconWindow(View* contents);
  // ...
  virtual void DrawContents();

private:
  const char* _bitmapName;
};

Window::Window(View* contents)
{
  cout << "Window::Window" << "\n";
}

void Window::DrawContents()
{
  cout << "void Window::DrawContents" << "\n";
}

void Window::SetOrigin(const Point& at)
{
  cout << "void Window::SetOrigin" << "\n";
}

void Window::DrawRect (const Point& p1, const Point& p2)
{
  cout << "void Window::DrawRect" << "\n";

  WindowImp* imp = GetWindowImp();
  //imp->DeviceRect(p1.X(), p1.Y(), p2.X(), p2.Y());
}

WindowImp* Window::GetWindowImp () {
  // WindowSystemFactory::Instance() returns an abstract factory that
  // manufactures all window system-specific objects. For simplicity, we've made
  // it a Singleton and have let the Window class access the factory directly.

  // if (_imp == 0) {
  //   _imp = WindowSystemFactory::Instance()->MakeWindowImp();
  // }

  // for simplicity I just returns windowImp
  _imp = new XWindowImp();

  return _imp;
}

ApplicationWindow::ApplicationWindow(View* contents):Window(contents)
{
  cout << "ApplicationWindow::ApplicationWindow(View* contents):(contents)" << "\n";
}

void ApplicationWindow::DrawContents ()
{
  cout << "void ApplicationWindow::DrawContents" << "\n";

  //GetView()->DrawOn(this);
}

IconWindow::IconWindow(View* contents):Window(contents)
{
  cout << "IconWindow::IconWindow(View* contents):Window(contents)" << "\n";
}

void IconWindow::DrawContents()
{
  cout << "void IconWindow::DrawContents" << "\n";

  WindowImp* imp = GetWindowImp();
  imp->DeviceRect(*new Coord(), *new Coord(), *new Coord(), *new Coord());

  // if (imp != 0) {
  //     imp->DeviceBitmap(_bitmapName, 0.0, 0.0);
  //   }
}

#endif /* WINDOW_H */



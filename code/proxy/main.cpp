#include <iostream>
#include "Graphic.cpp"
#include "Image.cpp"
#include "Point.cpp"
#include "ImageProxy.cpp"
#include "TextDocument.cpp"

using namespace std;

int main(int argc, char *argv[])
{
  cout << "main" << "\n" << "\n";

  // Graphic g;

  // const char* file = "file";    //指针方式
  // new Image(file);
  // Point* p = new Point();
  // Point p1(11,11);
  // cout <<"Point << " << p1 << "\n";
  // new ImageProxy(file);
  // new TextDocument();

  TextDocument* text = new TextDocument();
  ImageProxy* ip = new ImageProxy("anImageFileName");
  //Image* ip = new Image("file");
  text->Insert(ip);

  cout  << "\n" << "main end" << "\n";

  return 0;
}

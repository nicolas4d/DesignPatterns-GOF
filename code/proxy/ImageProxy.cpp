#ifndef IMAGEPROXY_H
#define IMAGEPROXY_H

#include "string.h"
#include "Graphic.cpp"
#include "Image.cpp"

using namespace std;

class ImageProxy : public Graphic {
public:
  ImageProxy(const char* imageFile);
  //virtual ~ImageProxy();
  virtual void Draw(const Point& at);
  virtual void HandleMouse(Event& event);
  virtual const Point& GetExtent();
  virtual void Load(istream& from);
  virtual void Save(ostream& to);
protected:
  Image* GetImage();
private:
  Image* _image;
  Point _extent;
  char* _fileName;
};


ImageProxy::ImageProxy (const char* fileName)
{
  cout << "ImageProxy::ImageProxy (const char* fileName)" << "\n";

  _fileName = strdup(fileName);
  //_extent = Point::Zero; // don't know extent yet
  _image = 0;
}

Image* ImageProxy::GetImage() {
  if (_image == 0) {
    _image = new Image(_fileName);
  }

  return _image;
}

const Point& ImageProxy::GetExtent () {
  if (_extent == Point::Zero) {
    _extent = GetImage()->GetExtent();
  }

  return _extent;
}

void ImageProxy::Draw (const Point& at)
{
  cout << "void ImageProxy::Draw (const Point& at)" << "\n";
  GetImage()->Draw(at);
}

void ImageProxy::HandleMouse (Event& event) {
  GetImage()->HandleMouse(event);
}

void ImageProxy::Save (ostream& to) {
  to << _extent << _fileName;
}

void ImageProxy::Load (istream& from) {
  from >> _extent >> _fileName;
}
#endif /* IMAGEPROXY_H */

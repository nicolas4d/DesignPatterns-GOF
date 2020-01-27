#ifndef IMAGE_H
#define IMAGE_H

#include "Graphic.cpp"

class Image : public Graphic {
public:
  Image(const char* file);
  // loads image from a file
  // virtual ~Image();
  virtual void Draw(const Point& at);
  virtual void HandleMouse(Event& event);
  virtual const Point& GetExtent();
  virtual void Load(istream& from);
  virtual void Save(ostream& to);
private:
  // ...
};

Image::Image(const char* file)
{
  std::cout << "Image::Image(const char* file)" << "\n";
}

void Image::Draw(const Point& at)
{
  std::cout << "void Image::Draw(const Point& at)" << "\n";
}

void Image::HandleMouse(Event& event)
{
  std::cout << "void Draw::HandleMouse(Event& event)" << "\n";
}

const Point& Image::GetExtent()
{
  std::cout << "Point& Draw::GetExtent()" << "\n";
}

void Image::Load(istream& from)
{
  std::cout << "void Draw::Load(istream& from)" << "\n";
}

void Image::Save(ostream& to)
{
  std::cout << "void Draw::Save(ostream& to)" << "\n";
}

#endif /* IMAGE_H */

#ifndef TEXTVIEW_H
#define TEXTVIEW_H

#include "visualComponent.cpp"

class TextView : public VisualComponent
{
public:
  TextView();
  virtual void Draw();
};

TextView::TextView()
{
  std::cout << "TextView::TextView()" << "\n";
}

void TextView::Draw()
{
  std::cout << "void TextView::Draw()" << "\n";
}

#endif /* TEXTVIEW_H */

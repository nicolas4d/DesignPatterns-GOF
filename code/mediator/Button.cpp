#ifndef BUTTON_H
#define BUTTON_H

class Widget;
class DialogDirector;
class MouseEvent;

class Button : public Widget {
public:
  Button(DialogDirector*);
  virtual void SetText(const char* text);
  virtual void HandleMouse(MouseEvent& event);
  // ...
};

Button::Button(DialogDirector* dd):Widget(dd)
{
  std::cout << "Button::Button(DialogDirector*)" << "\n";
}

void Button::SetText(const char* text)
{
  std::cout << "void Button::SetText(const char* text)" << "\n";
}

void Button::HandleMouse (MouseEvent& event) {
  // ...
  Changed();
}

#endif /* BUTTON_H */

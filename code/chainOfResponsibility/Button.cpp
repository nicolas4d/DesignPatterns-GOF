#ifndef BUTTON_H
#define BUTTON_H

#include "Widget.cpp"

class Button : public Widget {
public:
  Button(Widget* d, Topic t = NO_HELP_TOPIC);
  virtual void HandleHelp();
  // Widget operations that Button overrides...
};

Button::Button (Widget* h, Topic t) : Widget(h, t)
{
  std::cout << "Button::Button (Widget* h, Topic t) : Widget(h, t)" << "\n";
}

void Button::HandleHelp ()
{
  std::cout << "void Button::HandleHelp ()" << "\n";

  if (HasHelp()) {
    std::cout << "Button::HandleHelp" << "\n";
  } else {
    HelpHandler::HandleHelp();
  }
}

#endif /* BUTTON_H */

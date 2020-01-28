#ifndef WIDGET_H
#define WIDGET_H

#include "HelpHandler.cpp"

class Widget : public HelpHandler {
protected:
  Widget(Widget* parent = 0, Topic t = NO_HELP_TOPIC);
  
private:
  Widget* _parent;
};

Widget::Widget (Widget* w, Topic t) : HelpHandler(w, t)
{
  std::cout << "Widget::Widget (Widget* w, Topic t) : HelpHandler(w, t)" << "\n";

  _parent = w;
}

#endif /* WIDGET_H */

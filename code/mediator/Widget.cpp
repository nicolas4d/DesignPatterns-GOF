#ifndef WIDGET_H
#define WIDGET_H

class DialogDirector;
class MouseEvent;

class Widget {
public:
  Widget(DialogDirector*);
  virtual void Changed();
  virtual void HandleMouse(MouseEvent& event);
  // ...
private:
  DialogDirector* _director;
};

Widget::Widget(DialogDirector*)
{
  std::cout << "Widget::Widget(DialogDirector*)" << "\n";
}

void Widget::Changed ()
{
  _director->WidgetChanged(this);
}

void Widget::HandleMouse(MouseEvent& event)
{
  std::cout << "void Widget::HandleMouse(MouseEvent& event)" << "\n";
}

#endif /* WIDGET_H */

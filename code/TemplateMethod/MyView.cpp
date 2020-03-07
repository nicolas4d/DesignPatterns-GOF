#ifndef MYVIEW_H
#define MYVIEW_H

class View;

class MyView : public View
{
public:
  MyView();

  virtual void DoDisplay();
};

MyView::MyView(){}

void MyView::DoDisplay()
{
  std::cout << "void MyView::DoDisplay()" << "\n";
}

#endif /* MYVIEW_H */

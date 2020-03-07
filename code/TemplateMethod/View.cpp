#ifndef VIEW_H
#define VIEW_H

class View
{
public:
  View();

  void Display();
  void SetFocus();
  virtual void DoDisplay();
  void ResetFocus();
};

View::View()
{

}

void View::Display ()
{
  std::cout << "void View::Display ()" << "\n";

  SetFocus();
  DoDisplay();
  ResetFocus();
}

void View::SetFocus()
{
  std::cout << "void View::setFocus()" << "\n";
}

void View::DoDisplay(){}

void View::ResetFocus()
{
  std::cout <<"void View::ResetFocus()"  << "\n";
}

#endif /* VIEW_H */

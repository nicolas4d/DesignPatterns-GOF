#ifndef DIALOGDIRECTOR_H
#define DIALOGDIRECTOR_H

class Widget;

class DialogDirector {
public:
  //virtual ~DialogDirector();
  virtual void ShowDialog();
  virtual void WidgetChanged(Widget*) = 0;

protected:
  DialogDirector();
  virtual void CreateWidgets() = 0;
};

DialogDirector::DialogDirector()
{
  std::cout << "DialogDirector::DialogDirector()" << "\n";
}

void DialogDirector::ShowDialog()
{
  std::cout << "void DialogDirector::ShowDialog()" << "\n";
}

#endif /* DIALOGDIRECTOR_H */

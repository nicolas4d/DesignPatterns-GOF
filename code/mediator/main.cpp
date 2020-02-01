#include "iostream"

#include "DialogDirector.cpp"
#include "Widget.cpp"
#include "ListBox.cpp"
#include "EntryField.cpp"
#include "Button.cpp"
#include "FontDialogDirector.cpp"
#include "MouseEvent.cpp"

using namespace std;

int main(int argc, char *argv[])
{
  cout << "main" << "\n" << "\n";

  FontDialogDirector* fdd = new FontDialogDirector();
  cout << "\n";

  fdd->WidgetChanged(fdd->_ok);
  cout << "\n";

  fdd->WidgetChanged(fdd->_cancel);
  cout << "\n";

  fdd->WidgetChanged(fdd->_fontList);

  cout << "\n" << "main end" << "\n";

  return 0;
}

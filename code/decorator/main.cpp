#include <iostream>
#include "visualComponent.cpp"
#include "decorator.cpp"
#include "borderDecorator.cpp"
#include "window.cpp"
#include "textView.cpp"
#include "scrollDecorator.cpp"

using namespace std;

int main(int argc, char *argv[])
{
  cout << "mian" << "\n" << "\n";

  // VisualComponent* vc = new VisualComponent();
  // new Decorator(vc);
  // new BorderDecorator(vc, 1);
  // new Window();
  // new TextView();

  Window* window = new Window();
  TextView* textView = new TextView();

  cout <<  "\n";

  window->SetContents(textView);

  cout <<  "\n";

  window->SetContents(
                      new BorderDecorator(
                                          new ScrollDecorator(textView), 1
                                          )
                      );

  cout << "\n"<< "main end" << "\n";
  return 0;
}

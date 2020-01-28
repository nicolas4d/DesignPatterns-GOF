#include <iostream>
#include "HelpHandler.cpp"
#include "Widget.cpp"
#include "Button.cpp"
#include "Dialog.cpp"
#include "Application.cpp"

using namespace std;

const Topic PRINT_TOPIC = 1;
const Topic PAPER_ORIENTATION_TOPIC = 2;
const Topic APPLICATION_TOPIC = 3;

int main(int argc, char *argv[])
{
  cout << "main" << "\n" << "\n";

  // Application* application = new Application(APPLICATION_TOPIC);
  // Dialog* dialog = new Dialog(application, PRINT_TOPIC);
  // Button* button = new Button(dialog, PAPER_ORIENTATION_TOPIC);

  Application* application = new Application(NO_HELP_TOPIC);
  Dialog* dialog = new Dialog(application, NO_HELP_TOPIC);
  Button* button = new Button(dialog, NO_HELP_TOPIC);

  button->HandleHelp();

  cout << "\n" << "main end" << "\n";

  return 0;
}

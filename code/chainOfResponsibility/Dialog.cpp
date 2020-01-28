#ifndef DIALOG_H
#define DIALOG_H

#include "Widget.cpp"

class Dialog : public Widget {
public:
  Dialog(HelpHandler* h, Topic t = NO_HELP_TOPIC);
  virtual void HandleHelp();
  // Widget operations that Dialog overrides...
  // ...
};

Dialog::Dialog (HelpHandler* h, Topic t) : Widget(0)
{
  std::cout << "Dialog::Dialog (HelpHandler* h, Topic t) : Widget(0)" << "\n";

  SetHandler(h, t);
}

void Dialog::HandleHelp ()
{
  std::cout << "void Dialog::HandleHelp ()" << "\n";

  if (HasHelp()) {
    std::cout << "Dialog::HandleHelp" << "\n";
  } else {
    HelpHandler::HandleHelp();
  }
}

#endif /* DIALOG_H */

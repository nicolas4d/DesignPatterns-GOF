#ifndef HELPHANDLER_H
#define HELPHANDLER_H

typedef int Topic;
const Topic NO_HELP_TOPIC = -1;

class HelpHandler {
public:
  HelpHandler(HelpHandler* = 0, Topic = NO_HELP_TOPIC);

  virtual bool HasHelp();
  virtual void SetHandler(HelpHandler*, Topic);
  virtual void HandleHelp();

private:
  HelpHandler* _successor;
  Topic _topic;
};

HelpHandler::HelpHandler (
                          HelpHandler* h, Topic t
                          ) : _successor(h), _topic(t)
{
  std::cout << "HelpHandler::HelpHandler" << "\n";
}

bool HelpHandler::HasHelp ()
{
  std::cout << "bool HelpHandler::HasHelp ()" << "\n";

  return _topic != NO_HELP_TOPIC;
}

void HelpHandler::SetHandler(HelpHandler* hh, Topic t)
{
  std::cout << "void HelpHandler::SetHandler(HelpHandler* hh, Topic t)" << "\n";

  _successor = hh;
  _topic = t;
}

void HelpHandler::HandleHelp ()
{
  std::cout << "void HelpHandler::HandleHelp ()" << "\n";

  if (_successor != 0) {
    _successor->HandleHelp();
  }
}

#endif /* HELPHANDLER_H */

#ifndef APPLICATION_H
#define APPLICATION_H

#include "HelpHandler.cpp"

class Application : public HelpHandler {
public:
  Application(Topic t) : HelpHandler(0, t)
  {
    std::cout << "Application(Topic t) : HelpHandler(0, t)" << "\n";
  }
  
  virtual void HandleHelp();
  // application-specific operations...
};

void Application::HandleHelp ()
{
  std::cout << "void Application::HandleHelp ()" << "\n";

  // show a list of help topics
  std::cout << "Application::HandleHelp" << "\n";
}

#endif /* APPLICATION_H */

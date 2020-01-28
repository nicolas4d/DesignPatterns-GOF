#ifndef APPLICATION_H
#define APPLICATION_H

#include "Document.cpp"

class Application
{
public:
  Application();

  virtual void Add(Document*);
  // virtual ~Application();
};

Application::Application()
{
  std::cout << "Application::Application()" << "\n";
}

void Application::Add(Document* d)
{
  std::cout << "void Application::Add()" << "\n";
}
#endif /* APPLICATION_H */

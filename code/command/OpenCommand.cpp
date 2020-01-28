#ifndef OPENCOMMAND_H
#define OPENCOMMAND_H

#include "Command.cpp"
#include "Application.cpp"
#include "Document.cpp"

class OpenCommand : public Command {
public:
  OpenCommand(Application*);
  virtual void Execute();

protected:
  virtual const char* AskUser();

private:
  Application* _application;
  char* _response;
};

OpenCommand::OpenCommand (Application* a)
{
  std::cout << "OpenCommand::OpenCommand (Application* a)" << "\n";

  _application = a;
}

void OpenCommand::Execute ()
{
  std::cout << "void OpenCommand::Execute ()" << "\n";

  const char* name = AskUser();

  if (name != 0) {
    Document* document = new Document(name);

    _application->Add(document);
    document->Open();
  }
}

const char* OpenCommand::AskUser()
{
  std::cout << "const char* OpenCommand AskUser()" << "\n";

  return "document naem";
}

#endif /* OPENCOMMAND_H */

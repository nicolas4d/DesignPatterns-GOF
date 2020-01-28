#include <iostream>
#include "Application.cpp"
#include "Document.cpp"
#include "OpenCommand.cpp"
#include "PasteCommand.cpp"
#include "SimpleCommand.cpp"
#include "MyClass.cpp"

using namespace std;

int main(int argc, char *argv[])
{
  cout << "main" << "\n" << "\n";

  // new Application();
  // new Document("document name");
  // new OpenCommand(new Application());
  // new PasteCommand(new Document("Document name"));

  Application* a = new Application();
  OpenCommand* oc = new OpenCommand(a);
  oc->Execute();

  cout << "----" << "\n";

  Document* d = new Document("Document anme");
  PasteCommand* pc = new PasteCommand(d);
  pc->Execute();

  cout << "----" << "\n";

  MyClass* receiver = new MyClass;
  Command* aCommand =
    new SimpleCommand<MyClass>(receiver, &MyClass::Action);
  aCommand->Execute();

  cout << "\n" << "main end" << "\n";

  return 0;
}

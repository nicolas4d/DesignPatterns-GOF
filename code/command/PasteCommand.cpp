#ifndef PASTECOMMAND_H
#define PASTECOMMAND_H

#include "Command.cpp"
#include "Document.cpp"

class PasteCommand : public Command {
public:
  PasteCommand(Document*);
  virtual void Execute();

private:
  Document* _document;
};

PasteCommand::PasteCommand (Document* doc)
{
  std::cout << "PasteCommand::PasteCommand (Document* doc)" << "\n";

  _document = doc;
}

void PasteCommand::Execute ()
{
  std::cout << "void PasteCommand::Execute ()" << "\n";

  _document->Paste();
}

#endif /* PASTECOMMAND_H */

#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include<list>
#include "Command.cpp"

typedef list List;

class MacroCommand : public Command {
public:
  MacroCommand();
  //virtual ~MacroCommand();
  
  virtual void Add(Command*);
  virtual void Remove(Command*);
  virtual void Execute();
private:
  List<Command*>* _cmds;
};

MacroCommand::MacroCommand()
{
  std::cout << "MacroCommand::MacroCommand()" << "\n";
}

void MacroCommand::Execute () {
  ListIterator<Command*> i(_cmds);
  
  for (i.First(); !i.IsDone(); i.Next()) {
    Command* c = i.CurrentItem();
    c->Execute();
  }
}

void MacroCommand::Add (Command* c)
{
  _cmds->Append(c);
}

void MacroCommand::Remove (Command* c)
{
  _cmds->Remove(c);
}

#endif /* MACROCOMMAND_H */

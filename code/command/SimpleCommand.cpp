#ifndef SIMPLECOMMAND_H
#define SIMPLECOMMAND_H

#include "Command.cpp"

template <class Receiver>

class SimpleCommand : public Command {
public:
  typedef void (Receiver::* Action)();

  SimpleCommand(Receiver* r, Action a):_receiver(r), _action(a)
  {
    std::cout <<
      "SimpleCommand(Receiver* r, Action a):_receiver(r), _action(a)" << "\n";
  }

  virtual void Execute();

private:
  Action _action;
  Receiver* _receiver;
};

template <class Receiver>
void SimpleCommand<Receiver>::Execute ()
{
  std::cout << "void SimpleCommand<Receiver>::Execute ()" << "\n";

  (_receiver->*_action)();
}
#endif /* SIMPLECOMMAND_H */

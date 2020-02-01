#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

class Point;
class ConstraintSolverMemento;
class ConstraintSolver;
class Graphic;
// base class for graphical objects in the graphical editor

class MoveCommand {
public:
  MoveCommand(Graphic* target, const Point& delta);
  void Execute();
  void Unexecute();
  
private:
  ConstraintSolverMemento* _state;
  Point _delta;
  Graphic* _target;
};

MoveCommand::MoveCommand(Graphic* target, const Point& delta)
{
  std::cout << "MoveCommand::MoveCommand(Graphic* target, const Point& delta)" << "\n";
}

void MoveCommand::Execute () {
  ConstraintSolver* solver = ConstraintSolver::Instance();
  _state = solver->CreateMemento();
  // create a memento
  _target->Move(_delta);
  solver->Solve();
}

void MoveCommand::Unexecute () {
  ConstraintSolver* solver = ConstraintSolver::Instance();
  _target->Move(-_delta);
  solver->SetMemento(_state);
  // restore solver state
  solver->Solve();
}

#endif /* MOVECOMMAND_H */

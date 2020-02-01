#ifndef CONSTRAINTSOLVER_H
#define CONSTRAINTSOLVER_H

#include "ConstraintSolverMemento.cpp"

class Graphic;

class ConstraintSolver {
public:
  static ConstraintSolver* Instance();

  void Solve();
  void AddConstraint(
                     Graphic* startConnection, Graphic* endConnection
                     );
  void RemoveConstraint(
                        Graphic* startConnection, Graphic* endConnection
                        );
  ConstraintSolverMemento* CreateMemento();
  void SetMemento(ConstraintSolverMemento*);

protected:
  ConstraintSolver();

private:
  // nontrivial state and operations for enforcing
  // connectivity semantics
  static ConstraintSolver* _instance;
  ConstraintSolverMemento* _state;
  int _intState;
};

ConstraintSolver::ConstraintSolver(){}

ConstraintSolver* ConstraintSolver::_instance = 0;

ConstraintSolver* ConstraintSolver::Instance()
{
  if (_instance == 0) {
    _instance = new ConstraintSolver();
  }

  return _instance;
}

void ConstraintSolver::Solve()
{
  std::cout << "void ConstraintSolver::Solve()" << "\n";

  //AddConstraint()
}

void ConstraintSolver::AddConstraint(
                   Graphic* startConnection, Graphic* endConnection
                   )
{
  std::cout << "void ConstraintSolver::AddConstraint" << "\n";
}

void ConstraintSolver::RemoveConstraint(
                      Graphic* startConnection, Graphic* endConnection
                                        )
{
  std::cout << "void ConstraintSolver::RemoveConstraint" << "\n";
}

ConstraintSolverMemento* ConstraintSolver::CreateMemento()
{
  std::cout << "ConstraintSolverMemento* ConstraintSolver::CreateMemento()" << "\n";
  _intState = 1;
  _state = new ConstraintSolverMemento();
  _state->SetState(_intState);

  return _state;
}

void ConstraintSolver::SetMemento(ConstraintSolverMemento* state)
{
  std::cout << "void ConstraintSolver::SetMemento(ConstraintSolverMemento*)" << "\n";
  _state = state;
}

#endif /* CONSTRAINTSOLVER_H */

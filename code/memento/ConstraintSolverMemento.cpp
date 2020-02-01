#ifndef CONSTRAINTSOLVERMEMENTO_H
#define CONSTRAINTSOLVERMEMENTO_H

class ConstraintSolver;

class ConstraintSolverMemento {
  public:
  //virtual ~ConstraintSolverMemento();
  int GetState();
  void SetState(int);

  private:
  friend class ConstraintSolver;
  ConstraintSolverMemento();
  // private constraint solver state

  int _state;
};

ConstraintSolverMemento::ConstraintSolverMemento()
{
  std::cout << "ConstraintSolverMemento::ConstraintSolverMemento()" << "\n";

  _state = 10;
}

int ConstraintSolverMemento::GetState()
{
  return _state;
}

void ConstraintSolverMemento::SetState(int state)
{
  _state = state;
}

#endif /* CONSTRAINTSOLVERMEMENTO_H */

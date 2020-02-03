#ifndef SUBJECT_H
#define SUBJECT_H

#include "../FoundationClasses/List.cpp"
#include "../FoundationClasses/AbstractList.cpp"
#include "../iterator/ListIterator.cpp"
#include "../iterator/Iterator.cpp"

class Observer;

class Subject {
public:
  virtual ~Subject();
  virtual void Attach(Observer*);
  virtual void Detach(Observer*);
  virtual void Notify();
protected:
  Subject();
private:
  List<Observer*>* _observers;
};

Subject::Subject()
{
  std::cout << "Subject::Subject()" << "\n";
}

void Subject::Attach (Observer* o)
{
  std::cout << "void Subject::Attach (Observer* o)" << "\n";

  if (_observers == 0) {
    _observers = new List<Observer*>();
  }

  _observers->Append(o);
}

void Subject::Detach (Observer* o)
{
  std::cout << "void Subject::Detach (Observer* o)" << "\n";

  _observers->Remove(o);
}

void Subject::Notify () {

  std::cout << "void Subject::Notify () {" << "\n";

  ListIterator<Observer*> i(_observers);
  for (i.First(); !i.IsDone(); i.Next()) {
    i.CurrentItem()->Update(this);
  }
}

Subject::~Subject()
{
  std::cout << "virtual Subject::~Subject()" << "\n";
}

#endif /* SUBJECT_H */

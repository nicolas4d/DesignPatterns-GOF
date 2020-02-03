#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;
class Observer {
public:
  virtual ~Observer();
  virtual void Update(Subject* theChangedSubject) = 0;
protected:
  Observer();
};

Observer::Observer()
{
  std::cout << "Observer::Observer()" << "\n";
}
Observer::~Observer()
{
  std::cout << "Observer::~Observer()" << "\n";
}

#endif /* OBSERVER_H */

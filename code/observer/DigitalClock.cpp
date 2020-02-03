#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include "Widget.cpp"

class ClockTimer;
class Observer;
class Subject;

class DigitalClock: public Widget, public Observer {
public:
  DigitalClock(ClockTimer*);
  virtual ~DigitalClock();
  virtual void Update(Subject*);
  // overrides Observer operation

  virtual void Draw();
  // overrides Widget operation;
  // defines how to draw the digital clock
private:
  ClockTimer* _subject;
};

DigitalClock::DigitalClock (ClockTimer* s)
{
  std::cout << "DigitalClock::DigitalClock (ClockTimer* s)" << "\n";

  _subject = s;
  _subject->Attach(this);
}

DigitalClock::~DigitalClock ()
{
  std::cout << "DigitalClock::~DigitalClock ()" << "\n";

  _subject->Detach(this);
}

void DigitalClock::Update (Subject* theChangedSubject)
{
  std::cout << "void DigitalClock::Update (Subject* theChangedSubject)" << "\n";

  if (theChangedSubject == _subject) {
    Draw();
  }
}

void DigitalClock::Draw ()
{
  std::cout << "void DigitalClock::Draw ()" << "\n";

  // get the new values from the subject
  int hour = _subject->GetHour();
  int minute = _subject->GetMinute();
  // etc.
  std::cout << hour << "\n";
  std::cout << minute << "\n";
}

#endif /* DIGITALCLOCK_H */

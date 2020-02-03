#ifndef CLOCKTIMER_H
#define CLOCKTIMER_H

class Subject;

class ClockTimer : public Subject {
public:
  ClockTimer();
  virtual int GetHour();
  virtual int GetMinute();
  virtual int GetSecond();
  void Tick();
private:
  int _hour;
  int _minute;
  int _second;
};

ClockTimer::ClockTimer()
{
  std::cout << "ClockTimer::ClockTimer()" << "\n";
}

int ClockTimer::GetHour()
{
  return _hour;
}
int ClockTimer::GetMinute()
{
  return _minute;
}

int ClockTimer::GetSecond()
{
  return _second;
}

void ClockTimer::Tick ()
{
  std::cout << "void ClockTimer::Tick ()" << "\n";
  
  // update internal time-keeping state
  // ...
  _hour = 1;
  _minute = 1;
  _second = 1;

  Notify();
}

#endif /* CLOCKTIMER_H */

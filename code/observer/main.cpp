#include <iostream>
#include "Observer.cpp"
#include "Subject.cpp"
#include "ClockTimer.cpp"
#include "DigitalClock.cpp"
#include "Widget.cpp"
#include "AnalogClock.cpp"

using namespace std;

int main(int argc, char *argv[])
{
  cout << "main" << "\n" << "\n";

  ClockTimer* timer = new ClockTimer;
  // AnalogClock* analogClock = new AnalogClock(timer);
  DigitalClock* digitalClock = new DigitalClock(timer);

  timer->Tick();

  cout << "\n" << "main end" << "\n";

  return 0;
}

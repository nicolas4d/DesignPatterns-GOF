#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

class AnalogClock : public Widget, public Observer {
public:
  AnalogClock(ClockTimer*);
  virtual void Update(Subject*);
  virtual void Draw();
  // ...
};

#endif /* ANALOGCLOCK_H */

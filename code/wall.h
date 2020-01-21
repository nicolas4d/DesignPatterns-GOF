#ifndef WALL_H
#define WALL_H

#include "mapSite.h"

class Wall : public MapSite {
 public:
  Wall();

  virtual void Initialize();
  virtual Wall* Clone() const;

  virtual void Enter();
};

#endif

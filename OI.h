#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include <math.h>

class OI
{
private:
  Joystick* drive;
  Joystick* operator;
public:
  OI();

  inline float getDrive() { return addDeadZone(drive->GetX(), 0.15f); } // TODO: map
  inline float getTurn()  { return addDeadZone(drive->GetY(), 0.15f); } // TODO: map

  inline float addDeadZone(float original, float deadzone)
  {
    return ((fabs(original) <= deadzone) ? 0 : original);
  }
};

#endif

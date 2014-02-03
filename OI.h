#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include <math.h>

class OI
{
private:
  Joystick* joystickDrive;
  Joystick* joystickOperator;
public:
  OI();

  inline float getDrive() { return addDeadZone(joystickDrive->GetX(), 0.15f); } // TODO: map
  inline float getTurn()  { return addDeadZone(joystickDrive->GetY(), 0.15f); } // TODO: map

  inline float addDeadZone(float original, float deadzone)
  {
    return ((fabs(original) <= deadzone) ? 0 : original);
  }
};

#endif

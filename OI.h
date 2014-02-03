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

  inline float drive()     { return addDeadZone(joystickDrive->GetRawAxis(-1), 0.15f); }
  inline float turn()      { return addDeadZone(joystickDrive->GetRawAxis(-1), 0.15f); }
  inline bool  shiftHigh() { return joystickDrive->GetRawButton(-1); }
  inline bool  shiftLow()  { return joystickDrive->GetRawButton(-1); }
  inline bool  runPickup() { return joystickDrive->GetRawButton(-1); }


  inline float addDeadZone(float original, float deadzone)
  {
    return ((fabs(original) <= deadzone) ? 0 : original);
  }
};

#endif

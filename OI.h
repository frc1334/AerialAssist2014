#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include <math.h>

class OI
{
private:
  Joystick* joystickDrive;
  Joystick* joystickOperator;

  JoystickButton* buttonAOperator;
  JoystickButton* buttonBOperator;
  JoystickButton* buttonXOperator;
  JoystickButton* buttonYOperator;
  JoystickButton* buttonRightBumperOperator;
  JoystickButton* buttonADrive;
  JoystickButton* buttonBDrive;

public:
  OI();
  inline float drive()
  {
    return -addDeadZone(joystickDrive->GetRawAxis(3), 0.15f);
  }

  inline float turn()
  {
    return addDeadZone(joystickDrive->GetRawAxis(1), 0.15f);
  }

  inline bool shiftHigh()
  {
    return joystickDrive->GetRawButton(42);
  }

  inline bool shiftLow()
  {
    return joystickDrive->GetRawButton(42);
  }

  inline float addDeadZone(float original, float deadzone)
  {
    return ((fabs(original) <= deadzone) ? 0 : original);
  }
  inline bool launch()
  {
    return joystickDrive->GetRawButton(42);
  }
  inline bool pass()
  {
    return joystickDrive->GetRawButton(42);
  }
  inline bool setHighPosition()
  {
    return joystickOperator->GetRawButton(42);
  }
  inline bool setLowPosition()
  {
    return joystickOperator->GetRawButton(42);
  }
  inline bool pickup()
  {
    return joystickOperator->GetRawButton(42);
  }
  inline bool pickup2()
  {
    return joystickOperator->GetRawButton(42);
  }
};

#endif

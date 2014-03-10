#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include <math.h>

/**
  Operator interface
  Handles all user input
*/
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
  JoystickButton* buttonLeftBumperOperator;
  JoystickButton* buttonADrive;
  JoystickButton* buttonBDrive;
  JoystickButton* buttonXDrive;

public:
  OI();
  /** Retrieves the fwd/rev value for the drive */
  inline float drive()
  {
    return -addDeadZone(joystickDrive->GetRawAxis(3), 0.15f);
  }

  /** Retrieves the left/right value for the drive */
  inline float turn()
  {
    return addDeadZone(joystickDrive->GetRawAxis(1), 0.15f);
  }

  /** Returns status of shift up button */
  inline bool shiftHigh()
  {
    return joystickDrive->GetRawButton(6);
  }

  /** Returns status of shift down button */
  inline bool shiftLow()
  {
    return joystickDrive->GetRawButton(5);
  }

  /** Factors a deadzone into a given value */
  inline float addDeadZone(float original, float deadzone)
  {
    return ((fabs(original) <= deadzone) ? 0 : original);
  }
};

#endif

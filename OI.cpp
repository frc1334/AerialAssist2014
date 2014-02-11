#include "OI.h"
#include "Commands/OperatorHighCommand.h"
#include "Commands/OperatorLowCommand.h"
#include "Commands/OperatorCatchCommand.h"
#include "Commands/OperatorPickup1Command.h"
#include "Commands/OperatorPickup2Command.h"
#include "Commands/LaunchCommandGroup.h"
#include "Commands/OperatorPassCommand.h"
OI::OI()
{
  joystickDrive = new Joystick(1);
  joystickOperator = new Joystick(2);
  buttonAOperator = new JoystickButton(joystickOperator, 1);
  buttonBOperator = new JoystickButton(joystickOperator, 2);
  buttonXOperator = new JoystickButton(joystickOperator, 3);
  buttonYOperator = new JoystickButton(joystickOperator, 4);
  buttonRightBumperOperator = new JoystickButton(joystickOperator, 6);
  buttonADrive = new JoystickButton(joystickDrive, 1);
  buttonBDrive = new JoystickButton(joystickDrive, 2);

  buttonYOperator->WhenPressed(new OperatorHighCommand());
  buttonBOperator->WhenPressed(new OperatorLowCommand());
  buttonRightBumperOperator->WhenPressed(new OperatorCatchCommand());
  buttonAOperator->WhenPressed(new OperatorPickup1Command());
  buttonXOperator->WhenPressed(new OperatorPickup2Command());
  buttonADrive->WhenPressed(new LaunchCommandGroup());
  buttonBDrive->WhenPressed(new OperatorPassCommand());
}

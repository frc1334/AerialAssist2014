#include "OI.h"
#include "Commands/OperatorHighCommand.h"
#include "Commands/OperatorLowCommand.h"
#include "Commands/OperatorCatchCommand.h"
#include "Commands/OperatorPickup1Command.h"
#include "Commands/OperatorPickup2Command.h"
#include "Commands/DriveLaunchReleaseCommand.h"
#include "Commands/OperatorPassCommand.h"
#include "Commands/LoadCatapultGroup.h"
#include "Commands/MiddleCommandGroup.h"
#include "Commands/RollerOverrunCommand.h"

OI::OI()
{
  joystickDrive = new Joystick(1);
  joystickOperator = new Joystick(2);
  buttonAOperator = new JoystickButton(joystickOperator, 1);
  buttonBOperator = new JoystickButton(joystickOperator, 2);
  buttonXOperator = new JoystickButton(joystickOperator, 3);
  buttonYOperator = new JoystickButton(joystickOperator, 4);
  buttonLeftBumperOperator = new JoystickButton(joystickOperator, 5);
  buttonRightBumperOperator = new JoystickButton(joystickOperator, 6);

  buttonADrive = new JoystickButton(joystickDrive, 1);
  buttonBDrive = new JoystickButton(joystickDrive, 2);
  buttonXDrive = new JoystickButton(joystickDrive, 3);



  buttonXOperator->WhenPressed(new LoadCatapultGroup());
  buttonBOperator->WhenPressed(new OperatorLowCommand());
  buttonAOperator->WhenPressed(new OperatorPickup1Command());
  buttonAOperator->WhenReleased(new OperatorPickup2Command());
  buttonYOperator->WhenPressed(new OperatorHighCommand());
  buttonRightBumperOperator->WhileHeld(new OperatorCatchCommand());
  buttonRightBumperOperator->WhenReleased(new RollerOverrunCommand());
  //buttonLeftBumperOperator->WhileHeld(new MiddleCommandGroup());

  buttonADrive->WhenPressed(new DriveLaunchReleaseCommand());
  buttonBDrive->WhileHeld(new OperatorPassCommand());
}

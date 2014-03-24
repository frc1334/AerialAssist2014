#include "TwoBallCommandGroup.h"
#include "LoadCatapultGroup.h"
#include "Commands/WaitCommand.h"
#include "OperatorLowCommand.h"
#include "OperatorHighCommand.h"
#include "OperatorPickup1Command.h"
#include "OperatorPickup2Command.h"
#include "AutonomousPickupCommand.h"
#include "AutonomousDriveCommand.h"
#include "AutonomousLowGearCommand.h"
#include "DriveLaunchReleaseCommand.h"
#include "WinchRewindCommand.h"
#include "WinchRelaxCommand.h"

TwoBallCommandGroup::TwoBallCommandGroup()
{
  AddSequential(new AutonomousLowGearCommand());
  //AddSequential(new WinchRewindCommand());
  //AddSequential(new WaitCommand(0.1));
  //AddParallel(new WinchRelaxCommand());
  AddSequential(new AutonomousDriveCommand(1.0f, 0.0f, 2.2));
  AddSequential(new DriveLaunchReleaseCommand());
  AddSequential(new WinchRewindCommand());
  AddSequential(new WaitCommand(0.1));
  AddParallel(new WinchRelaxCommand());
  AddSequential(new OperatorLowCommand());
  AddSequential(new AutonomousPickupCommand(1.0));
  AddSequential(new OperatorPickup2Command());
  AddSequential(new OperatorHighCommand());
  AddSequential(new DriveLaunchReleaseCommand());
}

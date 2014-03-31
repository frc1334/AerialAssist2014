#include "FastOneBallCommandGroup.h"
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
#include "../Timing.h"

FastOneBallCommandGroup::FastOneBallCommandGroup()
{
  AddSequential(new AutonomousLowGearCommand());
  //AddSequential(new WinchRewindCommand());
  //AddSequential(new WaitCommand(0.1));
  //AddParallel(new WinchRelaxCommand());
  //AddSequential(new OperatorLowCommand());
  //AddSequential(new AutonomousPickupCommand(1.0));
  //AddSequential(new OperatorPickup2Command());
  AddParallel(new OperatorHighCommand());
  AddSequential(new AutonomousDriveCommand(1.0f, TURN_CORRECTION, 2.2));
  AddSequential(new DriveLaunchReleaseCommand());
}

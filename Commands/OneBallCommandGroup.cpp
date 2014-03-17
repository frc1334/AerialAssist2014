#include "OneBallCommandGroup.h"
#include "LoadCatapultGroup.h"
#include "Commands/WaitCommand.h"
#include "OperatorLowCommand.h"
#include "OperatorHighCommand.h"
#include "OperatorPickup1Command.h"
#include "OperatorPickup2Command.h"
#include "AutonomousPickupCommand.h"
#include "AutonomousDriveCommand.h"
#include "DriveLaunchReleaseCommand.h"

OneBallCommandGroup::OneBallCommandGroup()
{
  AddSequential(new LoadCatapultGroup());
  AddSequential(new OperatorLowCommand());
  AddSequential(new AutonomousPickupCommand(2.0));
  AddSequential(new OperatorPickup2Command());
  AddSequential(new OperatorHighCommand());
  AddSequential(new AutonomousDriveCommand(1.0f, 0.0f, 1.9));
  AddSequential(new DriveLaunchReleaseCommand());
}

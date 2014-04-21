#include "AutonomousModeRamGoal.h"
#include "LoadCatapultGroup.h"
#include "Commands/WaitCommand.h"
#include "OperatorLowCommand.h"
#include "OperatorHighCommand.h"
#include "OperatorPickup1Command.h"
#include "OperatorPickup2Command.h"
#include "AutonomousPickupCommand.h"
#include "AutonomousDriveCommand.h"
#include "AutonomousCoastCommand.h"
#include "AutonomousLowGearCommand.h"
#include "DriveLaunchReleaseCommand.h"
#include "OperatorPassCommand.h"
#include "../Timing.h"

AutonomousModeRamGoal::AutonomousModeRamGoal()
{
  AddSequential(new AutonomousLowGearCommand());
  AddSequential(new LoadCatapultGroup());
  AddSequential(new OperatorLowCommand());
  AddSequential(new AutonomousPickupCommand(2.0));
  AddSequential(new OperatorPickup2Command());
  AddSequential(new AutonomousDriveCommand(1.0f, TURN_CORRECTION, 2.5));
  AddParallel(new OperatorPassCommand()); // run with the timing command
  AddSequential(new WaitCommand(1.0));
  AddSequential(new OperatorHighCommand()); // cancel the pass
}

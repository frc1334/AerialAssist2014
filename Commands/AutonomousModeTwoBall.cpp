#include "AutonomousModeTwoBall.h"
#include "LoadCatapultGroup.h"
#include "Commands/WaitCommand.h"
#include "OperatorLowCommand.h"
#include "OperatorHighCommand.h"
#include "OperatorPickup1Command.h"
#include "OperatorPickup2Command.h"
#include "AutonomousPickupCommand.h"
#include "AutonomousDriveCommand.h"
#include "AutonomousLowGearCommand.h"
#include "AutonomousCoastCommand.h"
#include "DriveLaunchReleaseCommand.h"
#include "WinchRewindCommand.h"
#include "WinchRelaxCommand.h"
#include "../Timing.h"

AutonomousModeTwoBall::AutonomousModeTwoBall()
{
  AddSequential(new AutonomousLowGearCommand());
  AddSequential(new AutonomousDriveCommand(1.0f, TURN_CORRECTION, 2.2));
  AddParallel(new OperatorPickup2Command(0.5));
  AddSequential(new AutonomousCoastCommand(1.0f, TURN_CORRECTION, 0.0f, TURN_CORRECTION, 0.5));
  AddSequential(new DriveLaunchReleaseCommand());
  AddSequential(new WaitCommand(0.1));
  AddParallel(new AutonomousDriveCommand(0.0f, -1.0f, 0.5));
  AddSequential(new WinchRewindCommand());
  AddSequential(new WaitCommand(0.1));
  AddParallel(new WinchRelaxCommand());
  AddSequential(new OperatorLowCommand());
  AddSequential(new AutonomousDriveCommand(1.0f, TURN_CORRECTION, 2.2));
  AddSequential(new AutonomousCoastCommand(1.0f, TURN_CORRECTION, 0.0f, TURN_CORRECTION, 0.5));
  AddSequential(new AutonomousPickupCommand(1.0));
  AddSequential(new OperatorPickup2Command());
  AddSequential(new OperatorHighCommand());
  AddSequential(new AutonomousDriveCommand(0.0f, -1.0f, 0.5));
  AddSequential(new AutonomousDriveCommand(1.0f, TURN_CORRECTION, 2.2));
  AddSequential(new AutonomousCoastCommand(1.0f, TURN_CORRECTION, 0.0f, TURN_CORRECTION, 0.5));
  AddSequential(new DriveLaunchReleaseCommand());
}

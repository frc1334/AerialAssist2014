#include "AutonomousModeFastOneBall.h"
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
#include "WaitForHotCommand.h"
#include "../Timing.h"

AutonomousModeCheesyBall::AutonomousModeCheesyBall()
{
  AddSequential(new AutonomousLowGearCommand());
  AddParallel(new OperatorHighCommand());
  AddSequential(new AutonomousDriveCommand(1.0f, TURN_CORRECTION, 2.2));
  AddSequential(new WaitForHotCommand(5.0));
  AddSequential(new DriveLaunchReleaseCommand());
}

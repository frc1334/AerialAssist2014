#include "AutonomousModeMagicalMystery.h"
#include "AutonomousDriveCommand.h"
#include "AutonomousLowGearCommand.h"
#include "../Timing.h"

AutonomousModeMagicalMystery::AutonomousModeMagicalMystery()
{
  AddSequential(new AutonomousLowGearCommand());
  AddSequential(new AutonomousDriveCommand( 1.0f,  0.0f, 1.0));
  AddSequential(new AutonomousDriveCommand(-1.0f,  0.0f, 1.0));
  AddSequential(new AutonomousDriveCommand(-1.0f,  1.0f, 1.0));
  AddSequential(new AutonomousDriveCommand( 1.0f,  1.0f, 1.0));
  AddSequential(new AutonomousDriveCommand(-1.0f, -1.0f, 1.0));
  AddSequential(new AutonomousDriveCommand( 1.0f, -1.0f, 1.0));
  AddSequential(new AutonomousDriveCommand( 0.0f, -1.0f, 2.0));
  AddSequential(new AutonomousDriveCommand( 0.0f,  1.0f, 2.0));
}

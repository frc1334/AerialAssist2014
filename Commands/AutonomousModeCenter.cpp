#include "AutonomousModeCenter.h"
#include "AutonomousDriveCommand.h"
#include "VisionDataCollectCommand.h"
#include "TargetSwitchCommand.h"
#include "LaunchCommandGroup.h"
#include "../AutonomousTarget.h"
#include "WinchRewindCommand.h"


AutonomousModeCenter::AutonomousModeCenter()
{
// Add Commands here:
// e.g. AddSequential(new Command1());
//      AddSequential(new Command2());
// these will run in order.
// To run multiple commands at the same time,
//  /
//  / use AddParallel()
// e.g. AddParallel(new Command1());
//      AddSequential(new Command2());
// Command1 and Command2 will run in parallel.
// A command group will require all of the subsystems that each member
// would require.
// e.g. if Command1 requires chassis, and Command2 requires arm,
// a CommandGroup containing them would require both the chassis and the
// arm.
// shoot
  AddSequential (new WinchRewindCommand());
  AddSequential (new AutonomousDriveCommand(0.0,0.3,0.5));
  AddSequential (new VisionDataCollectCommand(Right));
  AddSequential (new AutonomousDriveCommand(0.0,-0.3,1.0));
  AddSequential (new VisionDataCollectCommand(Left));
  AddSequential (new AutonomousDriveCommand(0.0,0.3,0.5));
  AddSequential (new TargetSwitchCommand(new AutonomousDriveCommand (0.0,-0.3,0.5),new AutonomousDriveCommand(0.0,0.6,0.5)));
  AddSequential (new LaunchCommandGroup ());
  AddSequential (new AutonomousDriveCommand(1.0,0.0,0.8));
}

#include "AutonomousModeRight.h"
#include "AutonomousDriveCommand.h"
#include "VisionDataCollectCommand.h"
#include "TargetSwitchCommand.h"
#include "../AutonomousTarget.h"
AutonomousModeRight::AutonomousModeRight()
{
  AddSequential (new AutonomousDriveCommand(0.0,-0.3,0.5));
  AddSequential (new VisionDataCollectCommand(Left));
  AddSequential (new AutonomousDriveCommand(0.0,0.3,0.5));
  AddSequential (new VisionDataCollectCommand(Right));
  AddSequential (new TargetSwitchCommand(new AutonomousDriveCommand (0.0,-0.3,0.5),new AutonomousDriveCommand(0.0,0.3,0.5)));
  //AddSequential (new LaunchCommandGroup ());
  AddSequential (new AutonomousDriveCommand(1.0,0.0,0.8));
}

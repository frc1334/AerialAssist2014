#include "AutonomousModeRight.h"
#include "AutonomousDriveCommand.h"
#include "VisionDataCollectCommand.h"
#include "TargetSwitchCommand.h"
#include "LaunchCommandGroup.h"
AutonomousModeRight::AutonomousModeRight()
{
	AddSequential(new AutonomousDriveCommand(0.0f, 1.0f, 0.75));
}

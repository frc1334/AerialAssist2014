#include "AutonomousModeRight.h"
#include "AutonomousDriveCommand.h"
AutonomousModeRight::AutonomousModeRight()
{
	AddSequential(new AutonomousDriveCommand(0.0f, 1.0f, 0.75));
}

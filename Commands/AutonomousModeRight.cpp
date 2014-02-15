#include "AutonomousModeRight.h"
#include "AutonomousDriveCommand.h"
AutonomousModeRight::AutonomousModeRight()
{
	AddSequential(new AutonomousDriveCommand(0.0, 1.0, 0.15));
}

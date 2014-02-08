#include "XboxDriveCommand.h"

XboxDriveCommand::XboxDriveCommand() {
	Requires(drivetrain);
}

// Called just before this Command runs the first time
void XboxDriveCommand::Initialize() {
	
}

void XboxDriveCommand::Execute()
{
  drivetrain->arcadeDrive(oi->drive(), oi->turn());
  if (oi->shiftHigh())
    drivetrain->shift(true);
  if (oi->shiftLow())
    drivetrain->shift(false);
}

// Make this return true when this Command no longer needs to run execute()
bool XboxDriveCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void XboxDriveCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void XboxDriveCommand::Interrupted() {
}

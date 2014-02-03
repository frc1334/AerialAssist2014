#include "XboxDriveCommand.h"

XboxDriveCommand::XboxDriveCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void XboxDriveCommand::Initialize() {
	
}

<<<<<<< HEAD
// Called repeatedly when this Command is scheduled to run
void XboxDriveCommand::Execute() {
	
=======
void XboxDriveCommand::Execute()
{
  drivetrain->arcadeDrive(oi->drive(), oi->turn());
  if (oi->shiftHigh())
    drivetrain->shift(true);
  if (oi->shiftLow())
    drivetrain->shift(false);
>>>>>>> eeb8275... Finished drivetrain and createdpickup command
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

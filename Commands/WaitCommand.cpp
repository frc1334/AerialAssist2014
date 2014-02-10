#include "WaitCommand.h"

WaitCommand::WaitCommand()
{
  // Use requires() here to declare subsystem dependencies
  // eg. requires(chassis);
}

// Called just before this Command runs the first time
void WaitCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WaitCommand::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WaitCommand::IsFinished()
{
  return false;
}

// Called once after isFinished returns true
void WaitCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitCommand::Interrupted()
{
}

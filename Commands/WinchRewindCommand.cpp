#include "WinchRewindCommand.h"
/*Run the winch motor backward until the limit switch is pressed -> 
is finished is set to whether the limit switch is pressed*/

WinchRewindCommand::WinchRewindCommand()
{
  // Use requires() here to declare subsystem dependencies
  // eg. requires(chassis);
}

// Called just before this Command runs the first time
void WinchRewindCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WinchRewindCommand::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WinchRewindCommand::IsFinished()
{
  return false;
}

// Called once after isFinished returns true
void WinchRewindCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchRewindCommand::Interrupted()
{
}

#include "DriveLaunchReleaseCommand.h"

DriveLaunchReleaseCommand::DriveLaunchReleaseCommand()
{
  Requires (catapult);
  timer = new Timer();
}

// Called just before this Command runs the first time
void DriveLaunchReleaseCommand::Initialize()
{
  timer->Stop();
  timer->Reset();
}

// Called repeatedly when this Command is scheduled to run
void DriveLaunchReleaseCommand::Execute()
{
  if (timer->Get() == 0)
    timer->Start();
  catapult->open();
}

// Make this return true when this Command no longer needs to run execute()
bool DriveLaunchReleaseCommand::IsFinished()
{
  return timer->HasPeriodPassed(0.4f);
}

// Called once after isFinished returns true
void DriveLaunchReleaseCommand::End()
{
  timer->Stop();
  timer->Reset();
  catapult->setState(Launch);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveLaunchReleaseCommand::Interrupted()
{
	  timer->Stop();
	  timer->Reset();
}

#include "AutonomousLowGearCommand.h"

AutonomousLowGearCommand::AutonomousLowGearCommand()
{
  Requires(drivetrain);
}

// Called just before this Command runs the first time
void AutonomousLowGearCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutonomousLowGearCommand::Execute()
{
  drivetrain->shift(false);
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousLowGearCommand::IsFinished()
{
  return true;
}

// Called once after isFinished returns true
void AutonomousLowGearCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousLowGearCommand::Interrupted()
{
}

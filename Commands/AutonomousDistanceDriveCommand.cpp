#include "AutonomousDistanceDriveCommand.h"

AutonomousDistanceDriveCommand::AutonomousDistanceDriveCommand(float drive, float turn, double distance)
{
  this->drive = drive;
  this->turn = turn;
  this->distance = distance;
  Requires(drivetrain);
}

// Called just before this Command runs the first time
void AutonomousDistanceDriveCommand::Initialize()
{
  drivetrain->zeroDrive();
}

void AutonomousDistanceDriveCommand::Execute()
{
  drivetrain->arcadeDrive(drive, turn);
}

bool AutonomousDistanceDriveCommand::IsFinished()
{
  return drivetrain->getAbsoluteDistance() < distance;
}

void AutonomousDistanceDriveCommand::End()
{
  drivetrain->zeroDrive();
}

void AutonomousDistanceDriveCommand::Interrupted()
{
  drivetrain->zeroDrive();
}

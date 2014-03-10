#include "AutonomousDriveCommand.h"

AutonomousDriveCommand::AutonomousDriveCommand(float drive, float turn, double time)
{
  Requires(drivetrain);
  timer = new Timer();
  this->drive = drive;
  this->turn = turn;
  this->time = time;
}

void AutonomousDriveCommand::Initialize()
{
  timer->Stop();
  timer->Reset();
}

void AutonomousDriveCommand::Execute()
{
  if (timer->Get() == 0)
    timer->Start();
  drivetrain->arcadeDrive(drive, turn);
}

bool AutonomousDriveCommand::IsFinished()
{
  return timer->HasPeriodPassed(time);
}

void AutonomousDriveCommand::End()
{
  drivetrain->arcadeDrive(0, 0);
  timer->Stop();
  timer->Reset();
}

void AutonomousDriveCommand::Interrupted()
{
	  timer->Stop();
	  timer->Reset();
}

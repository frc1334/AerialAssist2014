#include "AutonomousDriveCommand.h"
#include <iostream>
#include <cstdio>
using namespace std;
AutonomousDriveCommand::AutonomousDriveCommand(float drive, float turn, double time)
{
  Requires(drivetrain);
  timer = new Timer();
  this->drive = drive;
  this->turn = turn;
  this->time = time;
  printf("AutoDriveCommand called: Params are: %f %f %f ", drive, turn, time);
}

void AutonomousDriveCommand::Initialize()
{
  timer->Stop();
  timer->Reset();
}

void AutonomousDriveCommand::Execute()
{
  drivetrain->arcadeDrive(drive, turn);
}

bool AutonomousDriveCommand::IsFinished()
{
  return timer->HasPeriodPassed(time);
}

void AutonomousDriveCommand::End()
{
  drivetrain->arcadeDrive(0, 0);
}

void AutonomousDriveCommand::Interrupted()
{
	printf("Autodrive command ended");
}

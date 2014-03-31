#include "AutonomousCoastCommand.h"

AutonomousCoastCommand::AutonomousCoastCommand(float startDrive, float startTurn, float endDrive, float endTurn, float time)
{
  Requires(drivetrain);
  timer = new Timer();
  this->startDrive = startDrive;
  this->startTurn = startTurn;
  this->endDrive = endDrive;
  this->endTurn = endTurn;
  this->time = time;
}

void AutonomousCoastCommand::Initialize()
{
  timer->Stop();
  timer->Reset();
}

void AutonomousCoastCommand::Execute()
{
  if (timer->Get() == 0)
    timer->Start();
  float driveLength = endDrive - startDrive;
  float turnLength = endTurn - startTurn;
  drivetrain->arcadeDrive(startDrive + (driveLength * (time - timer->Get())), startTurn + (turnLength * (time - timer->Get())));
}

bool AutonomousCoastCommand::IsFinished()
{
  return timer->HasPeriodPassed(time);
}

void AutonomousCoastCommand::End()
{
  drivetrain->arcadeDrive(0, 0);
  timer->Stop();
  timer->Reset();
}

void AutonomousCoastCommand::Interrupted()
{
  timer->Stop();
  timer->Reset();
}

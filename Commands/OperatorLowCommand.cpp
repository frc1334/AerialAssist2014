#include "OperatorLowCommand.h"
#include "OperatorLowPostCommand.h"

OperatorLowCommand::OperatorLowCommand()
{
  Requires(catapult);
}

void OperatorLowCommand::Initialize()
{
  timer->Reset();
}

void OperatorLowCommand::Execute()
{
  if (timer->Get() == 0)
  {
    catapult->setState(ShootState::LowShotPre);
    timer.Start();
  }
}

bool OperatorLowCommand::IsFinished()
{
  return timer->HasPeriodPassed(30.0f); // exit after solenoids have moved to position
  // starts the next command
}

void OperatorLowCommand::End()
{
  Scheduler::GetInstance()->AddCommand(new OperatorLowPostCommand());
}

void OperatorLowCommand::Interrupted()
{
  timer->Stop();
  timer->Reset();
}

#include "OperatorLowPostCommand.h"

OperatorLowPostCommand::OperatorLowPostCommand()
{
  Requires(catapult);
}

void OperatorLowPostCommand::Initialize()
{
}

void OperatorLowPostCommand::Execute()
{
  catapult->setState(ShootState::LowShotPost);
}

bool OperatorLowPostCommand::IsFinished()
{
  return true; // exit immediately
}

void OperatorLowPostCommand::End()
{
}

void OperatorLowPostCommand::Interrupted()
{
}

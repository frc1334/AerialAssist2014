#include "../ShootState.h"
#include "OperatorHighCommand.h"

OperatorHighCommand::OperatorHighCommand()
{
  Requires(catapult);
}

void OperatorHighCommand::Initialize()
{
}

void OperatorHighCommand::Execute()
{
  catapult->setState(ShootState::HighShot);
}

bool OperatorHighCommand::IsFinished()
{
  return true; // we want this to run once on press
  // so immediately finish
}

void OperatorHighCommand::End()
{
}

void OperatorHighCommand::Interrupted()
{
}

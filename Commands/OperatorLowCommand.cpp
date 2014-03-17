#include "OperatorLowCommand.h"

OperatorLowCommand::OperatorLowCommand()
{
  Requires(catapult);
}

void OperatorLowCommand::Initialize()
{
}

void OperatorLowCommand::Execute()
{
  catapult->setState(Low);
}

bool OperatorLowCommand::IsFinished()
{
  return true;
}

void OperatorLowCommand::End()
{
}

void OperatorLowCommand::Interrupted()
{
}

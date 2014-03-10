#include "OperatorCatchCommand.h"

OperatorCatchCommand::OperatorCatchCommand()
{
  Requires(catapult);
}

void OperatorCatchCommand::Initialize()
{
}

void OperatorCatchCommand::Execute()
{
  catapult->setState(Catch);
  catapult->setPickup(1.0f);
}

bool OperatorCatchCommand::IsFinished()
{
  return false;
}

void OperatorCatchCommand::End()
{
  catapult->setState(HighShot);
  catapult->setPickup(0.0f);
}

void OperatorCatchCommand::Interrupted()
{
  catapult->setState(HighShot);
  catapult->setPickup(0.0f);
}

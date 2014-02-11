#include "OPERATORPASSCOMMAND.h"

OperatorPassCommand::OperatorPassCommand()
{
  Requires(catapult);
}

void OperatorPassCommand::Initialize()
{
}

void OperatorPassCommand::Execute()
{
  catapult->setState(HighShot);
  catapult->setState(Pickup1);
  catapult->setPickup(-1.0);
}

bool OperatorPassCommand::IsFinished()
{
  return false; // run until cancelled
}

void OperatorPassCommand::End()
{
}

void OperatorPassCommand::Interrupted()
{
  catapult->setState(Pickup2Release);
  catapult->setPickup(0.0);
}

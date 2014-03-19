#include "OperatorPassCommand.h"

OperatorPassCommand::OperatorPassCommand()
{
  Requires(catapult);
}

void OperatorPassCommand::Initialize()
{
}

void OperatorPassCommand::Execute()
{
  catapult->setPickup(-1.0);
}

bool OperatorPassCommand::IsFinished()
{
  return false; // run until cancelled
}

void OperatorPassCommand::End()
{
  catapult->setPickup(0.0);
}

void OperatorPassCommand::Interrupted()
{
  catapult->setPickup(0.0);
}

#include "OperatorPickup1Command.h"

OperatorPickup1Command::OperatorPickup1Command()
{
  Requires(catapult);
}

void OperatorPickup1Command::Initialize()
{
}

void OperatorPickup1Command::Execute()
{
  catapult->setState(Pickup1);
}

bool OperatorPickup1Command::IsFinished()
{
  return true; // run once
}

void OperatorPickup1Command::End()
{
}

void OperatorPickup1Command::Interrupted()
{
}

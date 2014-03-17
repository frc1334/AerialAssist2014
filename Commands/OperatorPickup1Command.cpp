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
  catapult->setPickup(1.0f);
  catapult->setState(Pickup2Press);
}

bool OperatorPickup1Command::IsFinished()
{
  return false;
}

void OperatorPickup1Command::End()
{
  catapult->setPickup(0.0f);
}

void OperatorPickup1Command::Interrupted()
{
  catapult->setPickup(0.0f);
}

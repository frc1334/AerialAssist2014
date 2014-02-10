#include "OperatorPickup2Command.h"

OperatorPickup2Command::OperatorPickup2Command()
{
  Requires(catapult);
}

void OperatorPickup2Command::Initialize()
{
}

void OperatorPickup2Command::Execute()
{
  catapult->setState(ShootState::Pickup2Press);
}

bool OperatorPickup2Command::IsFinished()
{
  return false; // run until cancelled
}

void OperatorPickup2Command::End()
{
}

void OperatorPickup2Command::Interrupted()
{
  catapult->setState(ShootState::Pickup2Release);
}

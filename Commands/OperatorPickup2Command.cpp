#include "OperatorPickup2Command.h"
#include "../Timing.h"

OperatorPickup2Command::OperatorPickup2Command()
{
  Requires(catapult);
  timer = new Timer();
}

void OperatorPickup2Command::Initialize()
{
  timer->Stop();
  timer->Reset();
}

void OperatorPickup2Command::Execute()
{
  if (timer->Get() == 0)
    timer->Start();
  catapult->setPickup(1.0f);
  catapult->setState(Pickup2Release);
}

bool OperatorPickup2Command::IsFinished()
{
  return timer->HasPeriodPassed(PICKUP_WHEEL_OVERRUN);
}

void OperatorPickup2Command::End()
{
  timer->Stop();
  timer->Reset();
  catapult->setPickup(0.0f);
}

void OperatorPickup2Command::Interrupted()
{
  timer->Stop();
  timer->Reset();
  catapult->setPickup(0.0f);
}

#include "AutonomousPickupCommand.h"
#include "../Timing.h"

AutonomousPickupCommand::AutonomousPickupCommand(double time)
{
  Requires(catapult);
  timer = new Timer();
  this->time = time;
}

void AutonomousPickupCommand::Initialize()
{
  timer->Stop();
  timer->Reset();
}

void AutonomousPickupCommand::Execute()
{
  if (timer->Get() == 0)
    timer->Start();
  catapult->setPickup(1.0f);
  catapult->setState(Pickup2Press);
}

bool AutonomousPickupCommand::IsFinished()
{
  return timer->HasPeriodPassed(time);
}

void AutonomousPickupCommand::End()
{
  catapult->setPickup(0.0f);
  timer->Stop();
  timer->Reset();
}

void AutonomousPickupCommand::Interrupted()
{
  catapult->setPickup(0.0f);
  timer->Stop();
  timer->Reset();
}

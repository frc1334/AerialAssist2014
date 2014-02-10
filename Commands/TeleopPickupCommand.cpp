#include "TeleopPickupCommand.h"

TeleopPickupCommand::TeleopPickupCommand()
{
  Requires(pickup);
}

void TeleopPickupCommand::Initialize()
{
}

void TeleopPickupCommand::Execute()
{
  pickup->setPickup(oi->runPickup());
}

bool TeleopPickupCommand::IsFinished()
{
  return false; // default command; never finished
}

void TeleopPickupCommand::End()
{
}

void TeleopPickupCommand::Interrupted()
{
  // will not be interrupted
  // command runs during teleop
  // all other pickup commands run
  // during auto
}

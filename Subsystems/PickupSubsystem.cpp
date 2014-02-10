#include "PickupSubsystem.h"
#include "../Commands/TeleopPickupCommand.h"
#include "../Robotmap.h"

PickupSubsystem::PickupSubsystem() : Subsystem("PickupSubsystem")
{
  pick = new Talon(PICK_TALON);
  state = new Solenoid(PICK_STATE_SOLENOID);
}

void PickupSubsystem::InitDefaultCommand()
{
  SetDefaultCommand(new TeleopPickupCommand());
}

void PickupSubsystem::setPickup(bool pickup)
{
  pick->Set(pickup ? 1.0f : 0.0f);
  state->Set(pickup ? 1.0f : 0.0f);
}

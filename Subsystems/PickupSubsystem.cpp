#include "PickupSubsystem.h"
#include "../Robotmap.h"

PickupSubsystem::PickupSubsystem() : Subsystem("PickupSubsystem")
{
  pick = new Talon(PICK_TALON);
  state = new Talon(PICK_STATE_SOLENOID);
}

void PickupSubsystem::InitDefaultCommand()
{
}

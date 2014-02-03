#ifndef PICKUPSUBSYSTEM_H
#define PICKUPSUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class PickupSubsystem: public Subsystem
{
private:
  Talon* pick;
  Solenoid* state;
public:
  PickupSubsystem();
  void InitDefaultCommand();

  void setPickup(bool pickup);
};

#endif

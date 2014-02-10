#ifndef PICKUPSUBSYSTEM_H
#define PICKUPSUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class PickupSubsystem: public Subsystem
{
private:
  Talon* roller;
  Solenoid* extension;
  Solenoid* tilt;
  Solenoid* side;
public:
  PickupSubsystem();
  void InitDefaultCommand();

  //------------------------------------------------
  //Sets the corresponding state for the pickup
  //system
  //------------------------------------------------
  void setState(ShootState state);
};

#endif

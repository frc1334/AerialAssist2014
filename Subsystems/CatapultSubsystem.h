#ifndef CATAPULTSUBSYSTEM_H
#define CATAPULTSUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class CatapultSubsystem: public Subsystem
{
private:
  Talon winch1, winch2;
  Solenoid tilt, midlock, winchgear;
public:
  CatapultSubsystem();
  void InitDefaultCommand();
};

#endif

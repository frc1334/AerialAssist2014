#include "CatapultSubsystem.h"
#include "../Robotmap.h"

CatapultSubsystem::CatapultSubsystem() : Subsystem("CatapultSubsystem")
{
  winch1 = new Talon(WINCH_TALON_1);
  winch2 = new Talon(WINCH_TALON_2);
  tilt = new Solenoid(TILT_SOLENOID);
  midlock = new Solenoid(MIDLOCK_SOLENOID);
  winchgear = new Solenoid(WINCH_GEARBOX_SOLENOID);
}

void CatapultSubsystem::InitDefaultCommand()
{
}

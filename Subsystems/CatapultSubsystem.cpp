#include "CatapultSubsystem.h"
#include "../Robotmap.h"

CatapultSubsystem::CatapultSubsystem() : Subsystem("CatapultSubsystem")
{
  winch1 = new Talon(WINCH_TALON_1);
  winch2 = new Talon(WINCH_TALON_2);
  pickup = new Talon(PICKUP_TALON);
  launcherTilt = new Solenoid(LAUNCHER_TILT_SOLENOID);
  launcherOpen = new Solenoid(LAUNCHER_OPEN_SOLENOID);
  rollerExtend = new Solenoid(ROLLER_EXTEND_SOLENOID);
  winchGear = new Solenoid(WINCH_GEAR_SOLENOID);
  launcherMidlock = new Solenoid(LAUNCHER_MIDLOCK_SOLENOID);
  sideConstraints = new Solenoid(SIDE_CONSTRAINT_SOLENOID);
}

void CatapultSubsystem::InitDefaultCommand()
{
}

void CatapultSubsystem::setState(ShootState state)
{
  switch (state)
  {
  case HighShot:
    break;
  case LowShot:
    break;
  case Pickup1:
    break;
  case Pickup2Press:
    break;
  case Pickup2Release:
    break;
  case Catch:
    break;
  case Pass:
    break;
  case Launch:
    break;
  }
}

void CatapultSubsystem::setWinch(float speed)
{
  winch1->Set(speed);
  winch2->Set(speed);
}

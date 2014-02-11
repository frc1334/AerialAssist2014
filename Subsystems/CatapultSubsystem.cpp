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
	  launcherTilt->Set(false);
	  launcherOpen->Set(false);
	  rollerExtend->Set(false);
	  winchGear->Set(false);
	  launcherMidlock->Set(false);
	  sideConstraints->Set(false);
    break;
  case LowShotPre:
	  launcherTilt->Set(false);
    break;
  case LowShotPost:
	  launcherTilt->Set(true);
	  launcherMidlock->Set(true);
	  break;
  case Pickup1:
	  launcherTilt->Set(true);
	  rollerExtend->Set(true);
    break;
  case Pickup2Press:
	  rollerExtend->Set(true);
	  sideConstraints->Set(true);
    break;
  case Pickup2Release:
	  rollerExtend->Set(false);
	  sideConstraints->Set(false);
    break;
  case Catch:
	  sideConstraints->Set(true);
	  launcherOpen->Set(true);
	  sideConstraints->Set(true);
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
void CatapultSubsystem::setPickup(float speed)
{
  pickup->Set(speed);

}
bool CatapultSubsystem::getWinchLimitSwitch()
{
	return winchLimitSwitch->Get();
}

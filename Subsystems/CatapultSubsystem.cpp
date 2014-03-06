#include "CatapultSubsystem.h"
#include "../Robotmap.h"

CatapultSubsystem::CatapultSubsystem() : Subsystem("CatapultSubsystem")
{
  winch1 = new Talon(WINCH_TALON_1);
  winch2 = new Talon(WINCH_TALON_2);
  pickup = new Talon(PICKUP_TALON);
  launcherTilt = new DoubleSolenoidProxy(LAUNCHER_TILT_SOLENOID);
  launcherOpen = new DoubleSolenoidProxy(LAUNCHER_OPEN_SOLENOID);
  rollerExtend = new DoubleSolenoidProxy(ROLLER_EXTEND_SOLENOID);
  latch = new DoubleSolenoidProxy(LATCH_SOLENOID);
  launcherMidlock = new DoubleSolenoidProxy(LAUNCHER_MIDLOCK_SOLENOID);
  sideConstraints = new DoubleSolenoidProxy(SIDE_CONSTRAINT_SOLENOID);
  winchLimitSwitch = new DigitalInput(WINCH_SWITCH);
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
    unlock();
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
	unlock();
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
  return !winchLimitSwitch->Get();
}

void CatapultSubsystem::lock()
{
  latch->Set(true);
}

void CatapultSubsystem::unlock()
{
  latch->Set(false);
}

#include "CatapultSubsystem.h"
#include "../Robotmap.h"

CatapultSubsystem::CatapultSubsystem() : Subsystem("CatapultSubsystem")
{
  winch1 = new Talon(WINCH_TALON_1);
  winch2 = new Talon(WINCH_TALON_2);
  pickup = new Talon(PICKUP_TALON);
  launcherTilt = new DoubleSolenoidProxy(LAUNCHER_TILT_SOLENOID);
  launcherOpen = new DoubleSolenoidProxy(LAUNCHER_OPEN_SOLENOID);
  rollerExtend = new Solenoid(ROLLER_EXTEND_SOLENOID);
  latch = new DoubleSolenoidProxy(LATCH_SOLENOID);
  launcherMidlock = new DoubleSolenoidProxy(LAUNCHER_MIDLOCK_SOLENOID);
  sideConstraints = new DoubleSolenoidProxy(SIDE_CONSTRAINT_SOLENOID);
  winchLimitSwitch = new DigitalInput(WINCH_SWITCH);
  winchLatchSwitch = new DigitalInput(WINCH_LOADED_SWITCH);
  winchEncoder = new Encoder(WINCH_ENCODER_A, WINCH_ENCODER_B);
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
    rollerExtend->Set(true);
    //unlock();
    launcherMidlock->Set(false);
    sideConstraints->Set(false);
    break;
  case Middle:
	launcherMidlock->Set(true);
	break;
  case Pickup2Press:
	launcherTilt->Set(true);
    rollerExtend->Set(false);
    break;
  case Pickup2Release:
	launcherTilt->Set(true);
    rollerExtend->Set(true);
    break;
  case Catch:
    sideConstraints->Set(true);
    launcherOpen->Set(true);
    break;
  case Pass:
    break;
  case Launch:
	if (!isInLow())
	{
	  unlock();
	}
    break;
  }
}

void CatapultSubsystem::setWinch(float speed)
{
  if (safeReload())
  {
    winch1->Set(speed);
    winch2->Set(speed);
  }
}

void CatapultSubsystem::setPickup(float speed)
{
  pickup->Set(speed);
}

bool CatapultSubsystem::getWinchLimitSwitch()
{
  return !winchLimitSwitch->Get();
}

bool CatapultSubsystem::getWinchLatch()
{
  return winchLatchSwitch->Get();
}

void CatapultSubsystem::lock()
{
  latch->Set(true);
}

void CatapultSubsystem::unlock()
{
  latch->Set(false);
}

void CatapultSubsystem::open()
{
  launcherOpen->Set(true);
}

void CatapultSubsystem::close()
{
  launcherOpen->Set(false);
}

void CatapultSubsystem::zeroWinch()
{
  winchEncoder->Reset();
  winchEncoder->Start();
}

double CatapultSubsystem::readWinch()
{
  return winchEncoder->GetDistance();
}

bool CatapultSubsystem::safeReload()
{
  return (!isInLow()) && getWinchLatch();
}

bool CatapultSubsystem::isInLow()
{
  return launcherTilt->Get();
}

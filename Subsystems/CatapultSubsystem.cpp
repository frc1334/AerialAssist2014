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
  latch = new DoubleSolenoid(LATCH_SOLENOID_A, LATCH_SOLENOID_B);
//  launcherMidlock = new Solenoid(LAUNCHER_MIDLOCK_SOLENOID);
  sideConstraints = new Solenoid(SIDE_CONSTRAINT_SOLENOID);
  winchLimitSwitch = new DigitalInput(WINCH_SWITCH);
  winchEncoder = new Encoder(WINCH_ENCODER_A, WINCH_ENCODER_B);
  winchRamp = new Timer();
  winchRamp->Stop();
  winchRamp->Reset();
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
    //launcherMidlock->Set(false);
    sideConstraints->Set(false);
    break;
    break;
  case Pickup2Press:
    rollerExtend->Set(false);
    break;
  case Pickup2Release:
    rollerExtend->Set(true);
    break;
  case Catch:
    sideConstraints->Set(true);
    launcherOpen->Set(true);
    break;
  case Pass:
    break;
  case Low:
    launcherTilt->Set(true);
  case Launch:
    if (safeReload())
      unlock();
    break;
  }
}

void CatapultSubsystem::setWinch(WinchDirection direction)
{
  switch (direction)
  {
  case Forward:
    printf("Winch Forward");
    if (winchRamp->Get() == 0)
      winchRamp->Start();
    else
    {
      winch1->Set(winchRamp->Get() > 1.0 ? 1.0f : winchRamp->Get()); // TODO std::max
      winch2->Set(winchRamp->Get() > 1.0 ? 1.0f : winchRamp->Get());
    }
    break;
  case Reverse:
    printf("Winch Reverse");
    if (safeReload())
    {
      winch1->Set(-1.0f);
      winch2->Set(-1.0f);
    }
    winchRamp->Stop();
    winchRamp->Reset();
    break;
  case Off:
    printf("Winch Off");
    winch1->Set(0.0f);
    winch2->Set(0.0f);
    winchRamp->Stop();
    winchRamp->Reset();
    break;
  }
}

void CatapultSubsystem::setPickup(float speed)
{
  pickup->Set(speed);
}

bool CatapultSubsystem::getWinchLimitSwitch()
{
  return winchLimitSwitch->Get();
}

void CatapultSubsystem::lock()
{
  latch->Set(DoubleSolenoid::kForward);
}

void CatapultSubsystem::unlock()
{
  latch->Set(DoubleSolenoid::kReverse);
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
  return !isInLow();
}

bool CatapultSubsystem::isInLow()
{
  return launcherTilt->Get();
}

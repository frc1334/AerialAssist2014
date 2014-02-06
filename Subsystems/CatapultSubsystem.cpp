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

void CatapultSubsystem::setAngle(CatapultAngle angle)
{
	switch (angle)
	{
	case Catch:
	case HighShot:
		tilt->Set(false);
		midlock->Set(false);
		break;
	case LowShot:
		tilt->Set(true);
		midlock->Set(true);
		break;
	case Pickup:
		tilt->Set(true);
		midlock->Set(false);
		break;
	}
}

void CatapultSubsystem::setWinch(float speed)
{
	winch1->Set(speed);
	winch2->Set(speed);
}

void CatapultSubsystem::setWinchGear(bool gear)
{
	winchgear->Set(gear);
}

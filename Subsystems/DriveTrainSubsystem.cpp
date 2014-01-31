#include "DriveTrainSubsystem.h"
#include "../Robotmap.h"

DriveTrainSubsystem::DriveTrainSubsystem()
  : Subsystem("DriveTrainSubsystem")
{
	left1 = new Talon(LEFT_TALON_1);
	left2 = new Talon(LEFT_TALON_2);
	left3 = new Talon(LEFT_TALON_3);
	right1 = new Talon(RIGHT_TALON_1);
	right2 = new Talon(RIGHT_TALON_2);
	right3 = new Talon(RIGHT_TALON_3);
	shifter = new Solenoid(DRIVE_SOLENOID);
}

void DriveTrainSubsystem::InitDefaultCommand()
{
  //SetDefaultCommand(new MySpecialCommand());
}

void DriveTrainSubsystem::tankDrive(float left, float right)
{
  left1->Set(-(left));
  left2->Set(-(left));
  left2->Set(-(left));
  right1->Set(right);
  right2->Set(right);
  right2->Set(right);
}

void DriveTrainSubsystem::arcadeDrive(float drive, float turn)
{
  left1->Set(-(drive - turn));
  left2->Set(-(drive - turn));
  left3->Set(-(drive - turn));
  right1->Set(drive + turn);
  right2->Set(drive + turn);
  right3->Set(drive + turn);
}

void DriveTrainSubsystem::shift(bool highGear)
{
	shifter.Set(highGear);
}

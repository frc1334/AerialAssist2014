#include "DriveTrainSubsystem.h"
#include "../Commands/XboxDriveCommand.h"
#include "../Robotmap.h"

DriveTrainSubsystem::DriveTrainSubsystem()
  : Subsystem("DriveTrainSubsystem")
{
  left1 = new Talon(LEFT_TALON_1);
  left2 = new Talon(LEFT_TALON_2);
  right1 = new Talon(RIGHT_TALON_1);
  right2 = new Talon(RIGHT_TALON_2);
  shifter = new Solenoid(DRIVE_SOLENOID);
  leftDrive = new Encoder(DRIVE_LEFT_ENCODER_A, DRIVE_LEFT_ENCODER_B);
  rightDrive = new Encoder(DRIVE_RIGHT_ENCODER_A, DRIVE_RIGHT_ENCODER_B);
}

void DriveTrainSubsystem::InitDefaultCommand()
{
  SetDefaultCommand(new XboxDriveCommand());
}

void DriveTrainSubsystem::tankDrive(float left, float right)
{
  left1->Set(left);
  left2->Set(left);
  right1->Set(right);
  right2->Set(right);
}

void DriveTrainSubsystem::arcadeDrive(float drive, float turn)
{
  tankDrive((-turn) - drive, (-turn) + drive);
}

void DriveTrainSubsystem::shift(bool highGear)
{
  shifter->Set(highGear);
}

void DriveTrainSubsystem::zeroDrive()
{
  leftDrive->Reset();
  rightDrive->Reset();
  leftDrive->Start();
  rightDrive->Start();
}

double DriveTrainSubsystem::getAbsoluteDistance()
{
  return (fabs(leftDrive->GetDistance()) + fabs(rightDrive->GetDistance())) / 2;
}

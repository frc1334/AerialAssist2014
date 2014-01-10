#include "DriveTrainSubsystem.h"
#include "../Robotmap.h"

DriveTrainSubsystem::DriveTrainSubsystem() : Subsystem("DriveTrainSubsystem") {

}

void DriveTrainSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void DriveTrainSubsystem::tankDrive(float left, float right)
{
    left1.Set(-(left));
    left2.Set(-(left));
    right1.Set(right);
    right2.Set(right);
}

void DriveTrainSubsystem::arcadeDrive(float drive, float turn)
{
    left1.Set(-(drive - turn));
	left2.Set(-(drive - turn));
	right1.Set(drive + turn);
	right2.Set(drive + turn);
}

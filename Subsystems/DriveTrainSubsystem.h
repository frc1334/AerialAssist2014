#ifndef DRIVETRAINSUBSYSTEM_H
#define DRIVETRAINSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author p
 */
class DriveTrainSubsystem: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	Jaguar left1;
	Jaguar left2;
	Jaguar right1;
	Jaguar right2;

public:
	DriveTrainSubsystem();
	void InitDefaultCommand();

	void tankDrive(float left, float right);
	void arcadeDrive(float drive, float turn);
};

#endif

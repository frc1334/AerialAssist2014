#ifndef DRIVETRAINSUBSYSTEM_H
#define DRIVETRAINSUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrainSubsystem: public Subsystem
{
private:
  Talon* left1;
  Talon* left2;
  Talon* left3;
  Talon* right1;
  Talon* right2;
  Talon* right3;
  Solenoid* shifter;
public:
  DriveTrainSubsystem();
  void InitDefaultCommand();

  //------------------------------------------------
  //
  //------------------------------------------------
  void tankDrive(float left, float right);
  void arcadeDrive(float drive, float turn);
  void shift(bool highGear);
};

#endif

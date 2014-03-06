#ifndef DRIVETRAINSUBSYSTEM_H
#define DRIVETRAINSUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

#include "../DoubleSolenoidProxy.h" //TODO:remove when we get singles

/**
  Manages interactions with the components of the drivetrain
  Includes management of motors and gearshift
*/
class DriveTrainSubsystem: public Subsystem
{
private:
  Talon* left1;
  Talon* left2;
  Talon* right1;
  Talon* right2;
  DoubleSolenoidProxy* shifter;
public:
  DriveTrainSubsystem();

  /** Initializes the default command */
  void InitDefaultCommand();

  /**
    Drives the robot tank style
  */
  void tankDrive(float left, float right);
  /**
    Drives the robot arcade style
  */
  void arcadeDrive(float drive, float turn);
  /**
    Changes the state of the gearshift
  */
  void shift(bool highGear);
};

#endif

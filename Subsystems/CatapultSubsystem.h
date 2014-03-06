#ifndef CATAPULTSUBSYSTEM_H
#define CATAPULTSUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "../ShootState.h"
#include "WPILib.h"

#include "../DoubleSolenoidProxy.h" //TODO:remove when we get singles
											// ^ programming has plenty of singles

/**
Manages interactions with the catapult and pickup
mechanism
*/
class CatapultSubsystem: public Subsystem
{
private:
  Talon* winch1;
  Talon* winch2;
  Talon* pickup;
  DoubleSolenoidProxy* launcherTilt;
  DoubleSolenoidProxy* launcherOpen;
  DoubleSolenoidProxy* rollerExtend;
  DoubleSolenoidProxy* latch;
  DoubleSolenoidProxy* launcherMidlock;
  DoubleSolenoidProxy* sideConstraints;
  DigitalInput* winchLimitSwitch;

  //P1-launcherTilt
  //P2-launcherOpen
  //P3-rollerExtend
  //P4-latch
  //P5-launcherMidLock
  //P6-sideConstraints
public:
  CatapultSubsystem();

  /** Initializes the default command */
  void InitDefaultCommand();

  /**
    Sets the solenoid positions to match
    a given setting as defined in ShootState
  */
  void setState(ShootState state);
  /**
    Sets the winch motor direction and speed
  */
  void setWinch(float speed);
  /**
    Sets the robot into pick up
  */
  void setPickup(float speed);
  /**
    Tells you position of shooter
  */
  bool getWinchLimitSwitch();
  /**
    Locks the shooter mech.
   */
  void lock();
  /**
    Unlocks the shooter mech.
   */
  void unlock();
};

#endif

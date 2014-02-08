#ifndef CATAPULTSUBSYSTEM_H
#define CATAPULTSUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "../ShootState.h"
#include "WPILib.h"

class CatapultSubsystem: public Subsystem
{
private:
  Talon* winch1;
  Talon* winch2;
  Solenoid* tilt;		//P1
  Solenoid* midlock;	//P2
  Solenoid* winchgear;
public:
  CatapultSubsystem();
  void InitDefaultCommand();

  //------------------------------------------------
  //Sets the solenoid positions to match
  //a given setting as defined in ShootState
  //------------------------------------------------
  void setState(ShootState state);
  //------------------------------------------------
  //Sets the winch motor direction and speed 
  //------------------------------------------------
  void setWinch(float speed);
  //------------------------------------------------
  //Sets the gear to either neutral (false) or
  //engaged (true)
  //------------------------------------------------
  void setWinchGear(bool gear);
};

#endif

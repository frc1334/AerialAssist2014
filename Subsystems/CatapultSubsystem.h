#ifndef CATAPULTSUBSYSTEM_H
#define CATAPULTSUBSYSTEM_H

#include "Commands/Subsystem.h"
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
  enum CatapultAngle { HighShot, LowShot, Pickup, Catch };
  
  CatapultSubsystem();
  void InitDefaultCommand();
  
  void setAngle(CatapultAngle angle);
  void setWinch(float speed);
  void setWinchGear(bool gear);
};

#endif

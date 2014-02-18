#ifndef AUTONOMOUSDRIVECOMMAND_H
#define AUTONOMOUSDRIVECOMMAND_H

#include "../CommandBase.h"
/**
****************************************************************************************
 This command allows the AutonomousModeLeft, Centre, Right modes to follow the formate
of 1st diget being forward power, second diget being left right power, third diget being
the time it runs for.
****************************************************************************************
*/

class AutonomousDriveCommand: public CommandBase
{
private:
  Timer* timer;
  float drive, turn;
  double time;
public:
  AutonomousDriveCommand(float drive, float turn, double time);
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

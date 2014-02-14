#ifndef AUTONOMOUSDRIVECOMMAND_H
#define AUTONOMOUSDRIVECOMMAND_H

#include "../CommandBase.h"

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

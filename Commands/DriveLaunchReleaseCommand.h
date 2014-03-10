#ifndef DRIVELAUNCHRELEASECOMMAND_H
#define DRIVELAUNCHRELEASECOMMAND_H

#include "../CommandBase.h"

/**
***************************************************************************
It requires the catapult subsystem. Then it releases the ball.       
***************************************************************************
 */
class DriveLaunchReleaseCommand: public CommandBase
{
private:
  Timer *timer;
public:
  DriveLaunchReleaseCommand();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

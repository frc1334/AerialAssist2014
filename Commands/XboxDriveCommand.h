#ifndef XBOXDRIVECOMMAND_H
#define XBOXDRIVECOMMAND_H

#include "../CommandBase.h"

/**
*****************************************************************************
It requires the robot to have a drivetrain. This command runs throughout
the TeleOperated period, and allows an operator to interface with the Robot
using the Xbox 360 controller.
*****************************************************************************
*/

class XboxDriveCommand: public CommandBase
{
public:
  XboxDriveCommand();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

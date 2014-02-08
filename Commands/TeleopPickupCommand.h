#ifndef TELEOPPICKUPCOMMAND_H
#define TELEOPPICKUPCOMMAND_H

#include "../CommandBase.h"

class TeleopPickupCommand: public CommandBase
{
public:
  TeleopPickupCommand();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

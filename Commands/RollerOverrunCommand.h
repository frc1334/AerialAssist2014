#ifndef ROLLEROVERRUNCOMMAND_H
#define ROLLEROVERRUNCOMMAND_H

#include "../CommandBase.h"

/**
 The rollers roll for a few seconds after the catapult is released
 */
class RollerOverrunCommand: public CommandBase
{
private:
  Timer *timer;
public:
  RollerOverrunCommand();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

#ifndef WAITCOMMAND_H
#define WAITCOMMAND_H

#include "../CommandBase.h"

class WaitForHotCommand : public CommandBase
{
public:
  WaitForHotCommand(double timeout);
  WaitForHotCommand(const char *name, double timeout);
  virtual ~WaitForHotCommand() {}

protected:
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

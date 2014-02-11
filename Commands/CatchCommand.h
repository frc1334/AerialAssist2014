#ifndef CATCHCOMMAND_H
#define CATCHCOMMAND_H

#include "../CommandBase.h"

class CatchCommand: public CommandBase
{
public:
  CatchCommand();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

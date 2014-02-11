#ifndef OperatorCatchCommand_H
#define OperatorCatchCommand_H

#include "../CommandBase.h"

class OperatorCatchCommand: public CommandBase
{
public:
  OperatorCatchCommand();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

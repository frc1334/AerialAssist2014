#ifndef OPERATORCATCHCOMMAND_H
#define OPERATORCATCHCOMMAND_H

#include "../CommandBase.h"
#include "../ShootState.h"

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

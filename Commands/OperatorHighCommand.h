#ifndef OPERATORHIGHCOMMAND_H
#define OPERATORHIGHCOMMAND_H

#include "../CommandBase.h"

************************************************
Sets the Robot into the "High" position.
************************************************
class OperatorHighCommand: public CommandBase
{
public:
  OperatorHighCommand();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

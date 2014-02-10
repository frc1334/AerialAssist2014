#ifndef OPERATORHIGHCOMMAND_H
#define OPERATORHIGHCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author p
 */
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

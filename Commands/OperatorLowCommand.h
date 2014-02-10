#ifndef OPERATORLOWCOMMAND_H
#define OPERATORLOWCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author p
 */
class OperatorLowCommand: public CommandBase
{
public:
  OperatorLowCommand();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

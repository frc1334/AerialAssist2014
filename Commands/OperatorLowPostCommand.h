#ifndef OPERATORLOWPOSTCOMMAND_H
#define OPERATORLOWPOSTCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author p
 */
class OperatorLowPostCommand: public CommandBase
{
public:
  OperatorLowPostCommand();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

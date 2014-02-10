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
private:
  Timer* timer;
public:
  OperatorLowCommand();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

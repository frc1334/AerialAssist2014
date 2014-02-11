#ifndef OPERATORPASSCOMMAND_H
#define OPERATORPASSCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author p
 */
class OperatorPassCommand: public CommandBase
{
public:
  OperatorPassCommand();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

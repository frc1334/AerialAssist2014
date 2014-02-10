#ifndef OPERATORPICKUP2COMMAND_H
#define OPERATORPICKUP2COMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author p
 */
class OperatorPickup2Command: public CommandBase
{
public:
  OperatorPickup2Command();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

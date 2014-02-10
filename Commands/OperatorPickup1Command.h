#ifndef OPERATORPICKUP1COMMAND_H
#define OPERATORPICKUP1COMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author p
 */
class OperatorPickup1Command: public CommandBase
{
public:
  OperatorPickup1Command();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

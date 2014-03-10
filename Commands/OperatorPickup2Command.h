#ifndef OPERATORPICKUP2COMMAND_H
#define OPERATORPICKUP2COMMAND_H

#include "../CommandBase.h"
/**************************************************
This command enables the robot to pick up objects.
Uses commandbase. 
**************************************************/

class OperatorPickup2Command: public CommandBase
{
private:
  Timer *timer;
public:
  OperatorPickup2Command();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

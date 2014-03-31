#ifndef OPERATORPICKUP2COMMAND_H
#define OPERATORPICKUP2COMMAND_H

#include "../CommandBase.h"
#include "../Timing.h"
/**************************************************
This command enables the robot to pick up objects.
Uses commandbase.
**************************************************/

class OperatorPickup2Command: public CommandBase
{
private:
  Timer *timer;
  float overrun;
public:
  OperatorPickup2Command(float overrun = PICKUP_WHEEL_OVERRUN);
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

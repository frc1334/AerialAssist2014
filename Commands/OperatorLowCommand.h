#ifndef OPERATORLOWCOMMAND_H
#define OPERATORLOWCOMMAND_H

#include "../CommandBase.h"

/**
*******************************************************
The operator low command first requires the use of the
catapult. Then it resets the timer to zero just in case
the timer didn't already reset. Then we tell the robot 
that once the timer is equal to zero, the catapult can 
get ready to shoot, and the timer can start. Then the 
solenoids move into position, and then the commands wait
for 30 seconds. Then it pushes out the low post so that
it can shoot. 
*******************************************************
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

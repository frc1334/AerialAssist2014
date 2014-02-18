#ifndef OPERATORCATCHCOMMAND_H
#define OPERATORCATCHCOMMAND_H

#include "../CommandBase.h"
#include "../ShootState.h"

/**
***************************************************************
Operator catch command waits until another command asks for
the catapult. Once that is done the robot is set into a
catching state. Once this is interupted the robot will be set
in a highshot state.
***************************************************************
*/


class OperatorCatchCommand: public CommandBase
{
public:
  OperatorCatchCommand();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

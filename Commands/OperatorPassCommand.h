#ifndef OPERATORPASSCOMMAND_H
#define OPERATORPASSCOMMAND_H

#include "../CommandBase.h"

*******************************************************
This program makes the robot pass the ball with it's 
claw by lowering the ball and rolling it toward a 
teamate.
*******************************************************


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

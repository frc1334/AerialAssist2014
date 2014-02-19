#ifndef WINCHREWINDCOMMAND_H
#define WINCHREWINDCOMMAND_H

#include "../CommandBase.h"
/**
**********************************************************************
It requires a catapult and will rewind the winch once the command is
executed it will then wait till the winch reaches it's limit and set
the power for rewinding the winch to 0.
**********************************************************************
*/
class WinchRewindCommand: public CommandBase
{
public:
  WinchRewindCommand();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

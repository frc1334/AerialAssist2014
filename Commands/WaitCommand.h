#ifndef WAITCOMMAND_H
#define WAITCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author p
 */
class WaitCommand: public CommandBase
{
public:
  WaitCommand();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

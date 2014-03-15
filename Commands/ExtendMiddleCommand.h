#ifndef EXTENDMIDDLECOMMAND_H
#define EXTENDMIDDLECOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author p
 */
class ExtendMiddleCommand: public CommandBase
{
public:
  ExtendMiddleCommand();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

#include "MiddleCommandGroup.h"
#include "OperatorHighCommand.h"
#include "ExtendMiddleCommand.h"
#include "OperatorLowCommand.h"

MiddleCommandGroup::MiddleCommandGroup()
{
  AddSequential(new OperatorHighCommand());
  AddSequential(new WaitCommand(2.0));
  AddSequential(new ExtendMiddleCommand());
  AddSequential(new OperatorLowCommand());
}

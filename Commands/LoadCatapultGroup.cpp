#include "LoadCatapultGroup.h"
#include "WinchRewindCommand.h"
#include "WinchRelaxCommand.h"
#include "Commands/WaitCommand.h"

LoadCatapultGroup::LoadCatapultGroup()
{
  AddSequential(new WinchRewindCommand());
  AddSequential(new WaitCommand(0.3));
  AddSequential(new WinchRelaxCommand());
}

#include "LaunchCommandGroup.h"
#include "DriveLaunchReleaseCommand.h"
#include "WinchRewindCommand.h"
#include "Commands/WaitCommand.h"

LaunchCommandGroup::LaunchCommandGroup()
{
  AddSequential(new DriveLaunchReleaseCommand());
  AddSequential(new WaitCommand(5.0f));
  AddSequential(new WinchRewindCommand());
}

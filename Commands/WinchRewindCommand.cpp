#include "WinchRewindCommand.h"
/*Run the winch motor backward until the limit switch is pressed ->
is finished is set to whether the limit switch is pressed*/

WinchRewindCommand::WinchRewindCommand()
{
  Requires(catapult);
}

void WinchRewindCommand::Initialize()
{

}

void WinchRewindCommand::Execute()
{
  catapult->setWinch(-1.0);
}

bool WinchRewindCommand::IsFinished()
{
  return catapult->getWinchLimitSwitch();
}

void WinchRewindCommand::End()
{
  catapult->setWinch(0);
}

void WinchRewindCommand::Interrupted()
{
}

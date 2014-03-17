#include "WinchRewindCommand.h"
/*Run the winch motor backward until the limit switch is pressed ->
is finished is set to whether the limit switch is pressed*/

WinchRewindCommand::WinchRewindCommand()
{
  Requires(dummy);
  isRunning = false;
}

void WinchRewindCommand::Initialize()
{
}

void WinchRewindCommand::Execute()
{
  catapult->setWinch(CatapultSubsystem::Reverse);
  catapult->close();
  catapult->unlock();
  isRunning = true;
}

bool WinchRewindCommand::IsFinished()
{
  return catapult->getWinchLimitSwitch();
}

void WinchRewindCommand::End()
{
  catapult->setWinch(CatapultSubsystem::Off);
  catapult->lock();
  isRunning = false;
}

void WinchRewindCommand::Interrupted()
{
  isRunning = false;
}

void WinchRewindCommand::Start()
{
  printf("Winch Rewind Started");
  CommandBase::Start();
  catapult->zeroWinch();
  isRunning = true;
}

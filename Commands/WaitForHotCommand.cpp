#include "Commands/WaitForHotCommand.h"

WaitForHotCommand::WaitForHotCommand(double timeout) :
  CommandBase("WaitForHot", timeout)
{
  Requires(vision);
}

WaitForHotCommand::WaitForHotCommand(const char *name, double timeout) :
  CommandBase(name, timeout)
{
}

void WaitForHotCommand::Initialize()
{
}

void WaitForHotCommand::Execute()
{
}

bool WaitForHotCommand::IsFinished()
{
  return IsTimedOut() || vision->isHot(); // drop it like it's hot!
}

void WaitForHotCommand::End()
{
}

void WaitForHotCommand::Interrupted()
{
}

#include "Commands/WaitForHotCommand.h"

WaitForHotCommand::WaitForHotCommand(double timeout) :
  Command("WaitForHot", timeout)
{
  Requires(vision);
}

WaitForHotCommand::WaitForHotCommand(const char *name, double timeout) :
  Command(name, timeout)
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

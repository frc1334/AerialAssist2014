#include "ExtendMiddleCommand.h"

ExtendMiddleCommand::ExtendMiddleCommand()
{
  Requires(catapult);
}

void ExtendMiddleCommand::Initialize()
{
}

void ExtendMiddleCommand::Execute()
{
  catapult->setState(Middle);
}

bool ExtendMiddleCommand::IsFinished()
{
  return true;
}

void ExtendMiddleCommand::End()
{
}

void ExtendMiddleCommand::Interrupted()
{
}

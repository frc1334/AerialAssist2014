#include "WinchRelaxCommand.h"
#include <math.h>

WinchRelaxCommand::WinchRelaxCommand()
{
  Requires(catapult);
}

void WinchRelaxCommand::Initialize()
{
}

void WinchRelaxCommand::Execute()
{
  catapult->setWinch(1.0f);
}

bool WinchRelaxCommand::IsFinished()
{
  return fabs(catapult->readWinch()) < 50.0;
}

void WinchRelaxCommand::End()
{
  catapult->setWinch(0.0f);
}

void WinchRelaxCommand::Interrupted()
{
}

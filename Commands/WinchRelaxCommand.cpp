#include "WinchRelaxCommand.h"
#include <math.h>

WinchRelaxCommand::WinchRelaxCommand()
{
  Requires(dummy);
}

void WinchRelaxCommand::Initialize()
{
}

void WinchRelaxCommand::Execute()
{
  catapult->setWinch(CatapultSubsystem::Forward);
}

bool WinchRelaxCommand::IsFinished()
{
  return fabs(catapult->readWinch()) < 50.0;
}

void WinchRelaxCommand::End()
{
  catapult->setWinch(CatapultSubsystem::Off);
}

void WinchRelaxCommand::Interrupted()
{
  catapult->setWinch(CatapultSubsystem::Off);
}

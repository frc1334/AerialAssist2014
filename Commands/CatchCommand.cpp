#include "CatchCommand.h"

CatchCommand::CatchCommand()
{
}

void CatchCommand::Initialize()
{
}

void CatchCommand::Execute()
{
	catapult->setState(Catch);
}

bool CatchCommand::IsFinished()
{
  return false; 
}

void CatchCommand::End()
{
}

void CatchCommand::Interrupted()
{
	catapult->setState(HighShot);
}

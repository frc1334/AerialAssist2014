#include "OperatorCatchCommand.h"

OperatorCatchCommand::OperatorCatchCommand()
{
}

void OperatorCatchCommand::Initialize()
{
}

void OperatorCatchCommand::Execute()
{
	catapult->setState(Catch);
}

bool OperatorCatchCommand::IsFinished()
{
  return false; 
}

void OperatorCatchCommand::End()
{
}

void OperatorCatchCommand::Interrupted()
{
	catapult->setState(HighShot);
}

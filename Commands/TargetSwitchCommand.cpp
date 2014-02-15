#include "TargetSwitchCommand.h"

TargetSwitchCommand::TargetSwitchCommand(Command* left, Command* right)
{
  Requires(vision);
  this->left = left;
  this->right = right;
}

void TargetSwitchCommand::Initialize()
{
}

void TargetSwitchCommand::Execute()
{
  target = vision->guess();
  if (target == Left)
    left->Start();
  else
	right->Start();
}

bool TargetSwitchCommand::IsFinished()
{
  return (target == Left ? left : right)->IsFinished();
}

void TargetSwitchCommand::End()
{
}

void TargetSwitchCommand::Interrupted()
{
}

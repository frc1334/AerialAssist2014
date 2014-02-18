#include "VisionDataCollectCommand.h"

VisionDataCollectCommand::VisionDataCollectCommand(AutonomousTarget target)
{
  Requires(vision);
  timer = new Timer();
  this->target = target;
}

void VisionDataCollectCommand::Initialize()
{
  timer->Stop();
  timer->Reset();
}

void VisionDataCollectCommand::Execute()
{
  vision->collectData(target);
  if (timer->Get() == 0)
    timer->Start();
}

bool VisionDataCollectCommand::IsFinished()
{
  return timer->HasPeriodPassed(1.0);
}

void VisionDataCollectCommand::End()
{
  timer->Stop();
  timer->Reset();
}

void VisionDataCollectCommand::Interrupted()
{
  timer->Stop();
  timer->Reset();
}

#include "RollerOverrunCommand.h"
#include "../Timing.h"

RollerOverrunCommand::RollerOverrunCommand()
{
  Requires(catapult);
  timer = new Timer();
}

void RollerOverrunCommand::Initialize()
{
	  timer->Stop();
	  timer->Reset();
}

void RollerOverrunCommand::Execute()
{
	  if (timer->Get() == 0)
	    timer->Start();
	  catapult->setPickup(1.0);
}

bool RollerOverrunCommand::IsFinished()
{
	  return timer->HasPeriodPassed(CATCH_ROLLER_OVERRUN);
}

void RollerOverrunCommand::End()
{
	  catapult->setPickup(0.0);
	  timer->Stop();
	  timer->Reset();
}

void RollerOverrunCommand::Interrupted()
{
	  catapult->setPickup(0.0);
	  timer->Stop();
	  timer->Reset();
}

#include "XboxDriveCommand.h"

XboxDriveCommand::XboxDriveCommand()
{
  Requires(drivetrain);
}

void XboxDriveCommand::Initialize()
{
}

void XboxDriveCommand::Execute()
{
  drivetrain->arcadeDrive(oi->drive(), oi->turn());
  if (oi->shiftHigh())
    drivetrain->shift(true);
  if (oi->shiftLow())
    drivetrain->shift(false);
}

bool XboxDriveCommand::IsFinished()
{
  return false; // default command; never finished
}

void XboxDriveCommand::End()
{
}

void XboxDriveCommand::Interrupted()
{
  // will not be interrupted
  // command runs during teleop
  // all other drive commands run
  // during auto
}

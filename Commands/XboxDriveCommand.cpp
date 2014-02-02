#include "XboxDriveCommand.h"

XboxDriveCommand::XboxDriveCommand()
{
  requires(drivetrain);
}

void XboxDriveCommand::Initialize()
{
}

void XboxDriveCommand::Execute()
{
  drivetrain->arcadeDrive(oi->getDrive(), oi->getTurn());
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

#include "CommandBase.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name)
{
}

CommandBase::CommandBase() : Command()
{
}

VisionSubsystem* CommandBase::vision = NULL;
CatapultSubsystem* CommandBase::catapult = NULL;
DriveTrainSubsystem* CommandBase::drivetrain = NULL;
OI* CommandBase::oi = NULL;

void CommandBase::init()
{
  vision = new VisionSubsystem();
  catapult = new CatapultSubsystem();
  drivetrain = new DriveTrainSubsystem();

  oi = new OI();
}

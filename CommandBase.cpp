#include "CommandBase.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name, double timeout) : Command(name, timeout)
{
}

CommandBase::CommandBase(const char *name) : Command(name)
{
}

CommandBase::CommandBase() : Command()
{
}

VisionSubsystem* CommandBase::vision = NULL;
CatapultSubsystem* CommandBase::catapult = NULL;
DriveTrainSubsystem* CommandBase::drivetrain = NULL;
DummySubsystem* CommandBase::dummy = NULL;
OI* CommandBase::oi = NULL;

void CommandBase::init()
{
  vision = new VisionSubsystem();
  catapult = new CatapultSubsystem();
  drivetrain = new DriveTrainSubsystem();
  dummy = new DummySubsystem();

  oi = new OI();
}

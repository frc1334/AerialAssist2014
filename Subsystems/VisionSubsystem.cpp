#include "VisionSubsystem.h"
#include "../Robotmap.h"

VisionSubsystem::VisionSubsystem() : Subsystem("VisionSubsystem")
{
}

void VisionSubsystem::InitDefaultCommand()
{
}

bool VisionSubsystem::isHot()
{
  return CheesyVisionServer::GetInstance()->GetLeftStatus() && CheesyVisionServer::GetInstance()->GetRightStatus();
}

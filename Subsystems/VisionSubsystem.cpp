#include "VisionSubsystem.h"
#include "../Robotmap.h"

VisionSubsystem::VisionSubsystem() : Subsystem("VisionSubsystem")
{
  table = NetworkTable::GetTable("RoboRealm");
}

void VisionSubsystem::InitDefaultCommand()
{
}

int VisionSubsystem::getBlobCount()
{
  return (int)table -> GetNumber ("BLOB_COUNT");
}

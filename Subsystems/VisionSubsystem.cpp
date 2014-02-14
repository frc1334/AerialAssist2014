#include "VisionSubsystem.h"
#include "../Robotmap.h"

VisionSubsystem::VisionSubsystem() : Subsystem("VisionSubsystem")
{
	table = NetworkTable.getTable("RoboRealm");
}

void VisionSubsystem::InitDefaultCommand()
{
}

int VisionSubsystem::getBlobCount()
{
	return table -> getNumber ("BLOB_COUNT");
}

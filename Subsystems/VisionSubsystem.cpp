#include "VisionSubsystem.h"
#include "../Robotmap.h"

VisionSubsystem::VisionSubsystem() : Subsystem("VisionSubsystem")
{
  table = NetworkTable::GetTable("RoboRealm");
  left = new vector<unsigned int>();
  right = new vector<unsigned int>();
}

void VisionSubsystem::InitDefaultCommand()
{
}

int VisionSubsystem::getBlobCount()
{
  return (int)table->GetNumber("BLOB_COUNT");
}

void VisionSubsystem::collectData(AutonomousTarget target)
{
  (target == Left ? left : right)->push_back(getBlobCount()); // get the pointer to the appropriate vector and push current blob count back
}

AutonomousTarget VisionSubsystem::guess()
{
  int sumLeft = 0, sumRight = 0;
  for (unsigned int i = 0; i < left->size(); i++)
	  sumLeft += left->at(i);
  for (unsigned int i = 0; i < right->size(); i++)
	  sumRight += right->at(i);
  return ((sumLeft / left->size()) > (sumRight / right->size()) ? Left : Right); // calculate averages, return based on higher average
}

void VisionSubsystem::clearData()
{
  left->clear();
  right->clear();
}

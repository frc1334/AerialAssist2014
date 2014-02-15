#ifndef VISIONSUBSYSTEM_H
#define VISIONSUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../AutonomousTarget.h"

class VisionSubsystem: public Subsystem
{
private:
  NetworkTable* table;
  vector<unsigned int> *left, *right;
public:
  VisionSubsystem();
  void InitDefaultCommand();

  int getBlobCount();
  void collectData(AutonomousTarget target);
  AutonomousTarget guess();
  void clearData();
};

#endif

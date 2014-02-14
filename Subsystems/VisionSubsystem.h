#ifndef VISIONSUBSYSTEM_H
#define VISIONSUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class VisionSubsystem: public Subsystem
{
private:
  NetworkTable* table;

public:
  VisionSubsystem();
  void InitDefaultCommand();

  int getBlobCount();
};

#endif

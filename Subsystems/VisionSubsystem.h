#ifndef VISIONSUBSYSTEM_H
#define VISIONSUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class VisionSubsystem: public Subsystem
{
private:
public:
  VisionSubsystem();
  void InitDefaultCommand();
};

#endif

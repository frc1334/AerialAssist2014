#ifndef VISIONSUBSYSTEM_H
#define VISIONSUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Libraries/CheesyVisionServer.h"
#include "../AutonomousTarget.h"

class VisionSubsystem: public Subsystem
{
private:
public:
  VisionSubsystem();

  /** Initializes the default command */
  void InitDefaultCommand();

  bool isHot(); // are we 67?
};

#endif

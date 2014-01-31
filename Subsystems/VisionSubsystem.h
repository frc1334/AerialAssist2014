#ifndef VISIONSUBSYSTEM_H
#define VISIONSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author p
 */
class VisionSubsystem: public Subsystem
{
private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
public:
  VisionSubsystem();
  void InitDefaultCommand();
};

#endif

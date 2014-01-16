#ifndef CATAPULTSUBSYSTEM_H
#define CATAPULTSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author p
 */
class CatapultSubsystem: public Subsystem
{
private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
public:
  CatapultSubsystem();
  void InitDefaultCommand();
};

#endif

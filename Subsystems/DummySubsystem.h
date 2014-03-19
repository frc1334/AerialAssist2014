#ifndef DUMMYSUBSYSTEM_H
#define DUMMYSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
Prevents shooter from shooting in the low position
*/
class DummySubsystem: public Subsystem
{
private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
public:
  DummySubsystem();
  void InitDefaultCommand();
};

#endif

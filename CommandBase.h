#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Subsystems/VisionSubsystem.h"
#include "Subsystems/CatapultSubsystem.h"
#include "Subsystems/DriveTrainSubsystem.h"
#include "Commands/Command.h"
#include "OI.h"

class CommandBase: public Command
{
public:
  CommandBase(const char *name);
  CommandBase();
  static void init();
  
  static VisionSubsystem *vision;
  static CatapultSubsystem *catapult;
  static DriveTrainSubsystem *drivetrain;
  static OI *oi;
};

#endif

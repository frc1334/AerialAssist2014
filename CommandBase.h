#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Subsystems/VisionSubsystem.h"
#include "Subsystems/CatapultSubsystem.h"
#include "Subsystems/DriveTrainSubsystem.h"
#include "Commands/Command.h"
#include "OI.h"

/**
  Provides the base interface for all commands
  All instances of the subsystems exist here
*/
class CommandBase: public Command
{
public:
  CommandBase(const char* name);
  CommandBase();
  /** Inits the subsystems */
  static void init();

  static VisionSubsystem* vision;
  static CatapultSubsystem* catapult;
  static DriveTrainSubsystem* drivetrain;
  static OI* oi;
};

#endif

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

  /** Vision subsystem instance */
  static VisionSubsystem* vision;
  /** Launcher subsystem instance */
  static CatapultSubsystem* catapult;
  /** Drivetrain subsystem instance */
  static DriveTrainSubsystem* drivetrain;
  /** Operator interface instance */
  static OI* oi;
};

#endif

#ifndef VISIONSUBSYSTEM_H
#define VISIONSUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../AutonomousTarget.h"

// THIS -> https://github.com/FirstTeamExcel/Robot2014/blob/CheesyVision/CheesyVisionServer.h

/**
  Handles interactions with RoboRealm and the axis camera
*/
class VisionSubsystem: public Subsystem
{
private:
  NetworkTable* table;
  vector<unsigned int> *left, *right;
public:
  VisionSubsystem();

  /** Initializes the default command */
  void InitDefaultCommand();

  /** Retrieves the number of blobs seen by the camera */
  int getBlobCount();
  /** Gathers data on a given target and stores it */
  void collectData(AutonomousTarget target);
  /** Takes a guess on which target is hot */
  AutonomousTarget guess();
  /** Resets the stored data */
  void clearData();
};

#endif

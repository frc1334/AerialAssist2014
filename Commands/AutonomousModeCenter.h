#ifndef AUTONOMOUSMODECENTER_H
#define AUTONOMOUSMODECENTER_H

#include "Commands/CommandGroup.h"

/**
***************************************************************************
In autonomous, if the robot is set up in the center of the field, the
robot looks right, then it looks left, then it will shoot the ball to 
whatever goal is hot, then move forward into the goalie zone
***************************************************************************
*/
class AutonomousModeCenter: public CommandGroup
{
public:
  AutonomousModeCenter();
};

#endif

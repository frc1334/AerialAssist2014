#ifndef AUTONOMOUSMODERIGHT_H
#define AUTONOMOUSMODERIGHT_H

#include "Commands/CommandGroup.h"
/**
**********************************************************************************************
This command is when the robot (in autonomous) is setup on the right side of the field. It tells
the robot to look at the right target, then the left target, then depending on which goal is hot,
shoot it into that goal. Then drive forward into the goalie zone.
**********************************************************************************************
*/

class AutonomousModeRight: public CommandGroup
{
public:
  AutonomousModeRight();
};

#endif

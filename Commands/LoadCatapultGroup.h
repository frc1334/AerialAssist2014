#ifndef LOADCATAPULTGROUP_H
#define LOADCATAPULTGROUP_H

#include "Commands/CommandGroup.h"

/**
*************************************************************
this program will load the ball onto the robot using
the "claws" and the wheels attached, loading the robot
requires it to be in the low position unless it is catching
the ball
*************************************************************
**/

class LoadCatapultGroup: public CommandGroup
{
public:
  LoadCatapultGroup();
};

#endif

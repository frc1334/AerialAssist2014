#ifndef AUTONOMOUSMODELEFT_H
#define AUTONOMOUSMODELEFT_H

/**
**********************************************************************************************
This command runs the routine for the left mode of the autonomous mode. This will instantly
tell the Robot that it's looking at the left target. Then points the robot to the right target.
Once, it tells the robot it's looking at the right target it moves into the point-zone.
**********************************************************************************************
*/

#include "Commands/CommandGroup.h"

/**
 *
 *
 * @author p
 */
class AutonomousModeLeft: public CommandGroup
{
public:
  AutonomousModeLeft();
};

#endif

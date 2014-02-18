#ifndef VISIONDATACOLLECTCOMMAND_H
#define VISIONDATACOLLECTCOMMAND_H

#include "../CommandBase.h"
#include "../AutonomousTarget.h"

/*
**************************************************************************************
 The Vision collect subsystem features a few critical function for "discovering" the
hot goal. The "magic" happens in the "Execute" feild. In this feild the camera starts
collecting data from the camera and then you must define a target (Left or Right)
you will then set a timer which will analyze the information given for a set time.
**************************************************************************************
*/

class VisionDataCollectCommand: public CommandBase
{
private:
  Timer* timer;
  AutonomousTarget target;
public:
	VisionDataCollectCommand(AutonomousTarget target);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

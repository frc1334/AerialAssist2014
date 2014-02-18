#ifndef TARGETSWITCHCOMMAND_H
#define TARGETSWITCHCOMMAND_H

#include "../CommandBase.h"
#include "../AutonomousTarget.h"

/**
***************************************************************************
It requires the vision subsystem, then it saves the variables of the left 
or right target, then depending on what target is "hot" , it will go back
to that variable (left or right) and pick the hot one, and run that command
***************************************************************************
*/

class TargetSwitchCommand: public CommandBase
{
private:
	Command *left, *right;
	AutonomousTarget target;
public:
	TargetSwitchCommand(Command* left, Command* right);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

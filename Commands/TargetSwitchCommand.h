#ifndef TARGETSWITCHCOMMAND_H
#define TARGETSWITCHCOMMAND_H

#include "../CommandBase.h"
#include "../AutonomousTarget.h"

class TargetSwitchCommand: public CommandBase
{
private:
	Command *left, *right;
public:
	TargetSwitchCommand(Command* left, Command* right);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

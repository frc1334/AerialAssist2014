#ifndef AUTONOMOUSLOWGEARCOMMAND_H
#define AUTONOMOUSLOWGEARCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author p
 */
class AutonomousLowGearCommand: public CommandBase {
public:
	AutonomousLowGearCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

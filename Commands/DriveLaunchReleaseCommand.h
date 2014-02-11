#ifndef DRIVELAUNCHRELEASECOMMAND_H
#define DRIVELAUNCHRELEASECOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author p
 */
class DriveLaunchReleaseCommand: public CommandBase {
public:
	DriveLaunchReleaseCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

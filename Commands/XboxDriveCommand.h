#ifndef XBOXDRIVECOMMAND_H
#define XBOXDRIVECOMMAND_H

#include "../CommandBase.h"

class XboxDriveCommand: public CommandBase
{
public:
	XboxDriveCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

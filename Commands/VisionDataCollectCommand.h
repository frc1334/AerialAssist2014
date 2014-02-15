#ifndef VISIONDATACOLLECTCOMMAND_H
#define VISIONDATACOLLECTCOMMAND_H

#include "../CommandBase.h"
#include "../AutonomousTarget.h"

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

#ifndef AUTONOMOUSPICKUPCOMMAND_H
#define AUTONOMOUSPICKUPCOMMAND_H

#include "../CommandBase.h"

class AutonomousPickupCommand: public CommandBase
{
private:
  Timer* timer;
  double time;
public:
	AutonomousPickupCommand(double time);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

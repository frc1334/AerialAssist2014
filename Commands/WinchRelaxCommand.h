#ifndef WINCHRELAXCOMMAND_H
#define WINCHRELAXCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author p
 */
class WinchRelaxCommand: public CommandBase {
public:
	WinchRelaxCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

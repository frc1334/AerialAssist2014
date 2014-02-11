#ifndef WINCHREWINDCOMMAND_H
#define WINCHREWINDCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author p
 */
class WinchRewindCommand: public CommandBase {
public:
	WinchRewindCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

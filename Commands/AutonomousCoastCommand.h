#ifndef AUTONOMOUSCOASTCOMMAND_H
#define AUTONOMOUSCOASTCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author p
 */
class AutonomousCoastCommand: public CommandBase
{
private:
  float startDrive;
  float startTurn;
  float endDrive;
  float endTurn;
  float time;
  Timer *timer;
public:
  AutonomousCoastCommand(float startDrive, float startTurn, float endDrive, float endTurn, float time);
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

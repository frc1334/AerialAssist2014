#ifndef AUTONOMOUSDISTANCEDRIVECOMMAND_H
#define AUTONOMOUSDISTANCEDRIVECOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author p
 */
class AutonomousDistanceDriveCommand: public CommandBase
{
private:
  float drive, turn;
  double distance;
public:
  AutonomousDistanceDriveCommand(float drive, float turn, double distance);
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif

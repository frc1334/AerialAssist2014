#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"

class CommandBasedRobot : public IterativeRobot
{
private:
  LiveWindow *lw;

  virtual void RobotInit()
  {
    CommandBase::init();
    lw = LiveWindow::GetInstance();
  }

  virtual void AutonomousInit()
  {
  }

  virtual void AutonomousPeriodic()
  {
    Scheduler::GetInstance()->Run();
  }

  virtual void TeleopInit()
  {
  }

  virtual void TeleopPeriodic()
  {
    Scheduler::GetInstance()->Run();
  }

  virtual void TestPeriodic()
  {
    lw->Run();
  }
};

START_ROBOT_CLASS(CommandBasedRobot);


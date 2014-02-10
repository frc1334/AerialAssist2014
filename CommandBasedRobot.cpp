#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Robotmap.h"

class CommandBasedRobot : public IterativeRobot
{
private:
  LiveWindow* lw;
  Compressor* compressor;

  virtual void RobotInit()
  {
    CommandBase::init();
    lw = LiveWindow::GetInstance();
    compressor = new Compressor(COMPRESSOR_RELAY, COMPRESSOR_SWITCH);
  }

  virtual void AutonomousInit()
  {
	  compressor->Start();
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


#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Robotmap.h"
#include "Commands/AutonomousModeLeft.h"
#include "Commands/AutonomousModeCenter.h"
#include "Commands/AutonomousModeRight.h"

class CommandBasedRobot : public IterativeRobot
{
private:
  LiveWindow* lw;
  Compressor* compressor;
  AutonomousModeLeft* left;
  AutonomousModeCenter* center;
  AutonomousModeRight* right;

  virtual void RobotInit()
  {
    CommandBase::init();
    lw = LiveWindow::GetInstance();
    compressor = new Compressor(COMPRESSOR_RELAY, COMPRESSOR_SWITCH);
    left = new AutonomousModeLeft();
    center = new AutonomousModeCenter();
    right = new AutonomousModeRight();
  }

  virtual void AutonomousInit()
  {
    compressor->Start();
    left->Start();
    //center->Start();
    //right->Start();
  }

  virtual void AutonomousPeriodic()
  {
    Scheduler::GetInstance()->Run();
  }

  virtual void TeleopInit()
  {
    left->Cancel();
    center->Cancel();
    right->Cancel();
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


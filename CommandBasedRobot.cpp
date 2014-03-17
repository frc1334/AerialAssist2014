#include "WPILib.h"
#include "CommandBase.h"
#include "Commands/Command.h"
#include "Commands/OneBallCommandGroup.h"
#include "Commands/WinchRewindCommand.h"
#include "Commands/WinchRelaxCommand.h"
#include "Commands/LoadCatapultGroup.h"
#include "Subsystems/CatapultSubsystem.h"
#include "Robotmap.h"

/**
  Main robot class
*/
class CommandBasedRobot : public IterativeRobot
{
private:
  LiveWindow* lw;
  Compressor* compressor;
  Command* autoCommand;

  /** Runs when the robot starts up */
  virtual void RobotInit()
  {
    CommandBase::init();
    lw = LiveWindow::GetInstance();
    compressor = new Compressor(COMPRESSOR_RELAY, COMPRESSOR_SWITCH);
    autoCommand = new OneBallCommandGroup();
    //choice->AddDefault("One Ball", new OneBallCommandGroup());
    //SmartDashboard::PutData("Autonomous Mode", choice);
  }

  /** Initializes an autonomous session */
  virtual void AutonomousInit()
  {
    compressor->Start();
    CommandBase::catapult->zeroWinch();
    autoCommand->Start();
  }

  /** Runs continously during autonomous */
  virtual void AutonomousPeriodic()
  {
    Scheduler::GetInstance()->Run();
  }

  /** Initializes a teleop session */
  virtual void TeleopInit()
  {
    compressor->Start();
    CommandBase::catapult->zeroWinch();
    //(new LoadCatapultGroup())->Start();
    //(new LaunchCommandGroup())->Start();
  }

  /** Runs continously during teleop */
  virtual void TeleopPeriodic()
  {
    Scheduler::GetInstance()->Run();
    //printf("L:%d S-R:%d W-L:%d E:%d W:%f\n", CommandBase::catapult->isInLow(), CommandBase::catapult->safeReload(), CommandBase::catapult->getWinchLimitSwitch(), CommandBase::catapult->winchEncoder->GetDistance(), isRunning);
  }

  virtual void TestPeriodic()
  {
    //printf("Switch readout: %f", CommandBase::catapult->getWinchLimitSwitch() ? 1.0f : 0.0f);
    //lw->Run();
  }
};

START_ROBOT_CLASS(CommandBasedRobot);

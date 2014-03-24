#include "WPILib.h"
#include "CommandBase.h"
#include "Commands/Command.h"
#include "Commands/OneBallCommandGroup.h"
#include "Commands/TwoBallCommandGroup.h"
#include "Commands/FastOneBallCommandGroup.h"
#include "Commands/AutonomousDriveCommand.h"
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
  SendableChooser* autoMode;

  /** Runs when the robot starts up */
  virtual void RobotInit()
  {
    CommandBase::init();
    lw = LiveWindow::GetInstance();
    compressor = new Compressor(COMPRESSOR_SWITCH, COMPRESSOR_RELAY);
    autoCommand = new OneBallCommandGroup();
    autoMode = new SendableChooser();
    autoMode->AddDefault("One Ball", new OneBallCommandGroup());
    autoMode->AddObject("Fast One Ball", new FastOneBallCommandGroup());
    autoMode->AddObject("Deux Ball", new TwoBallCommandGroup());
    autoMode->AddObject("Just Friggin Drive", new AutonomousDriveCommand(1.0f, 0.0f, 2.0));
    SmartDashboard::PutData("Autonomous Mode", autoMode);
  }

  /** Initializes an autonomous session */
  virtual void AutonomousInit()
  {
    compressor->Start();
    CommandBase::catapult->zeroWinch();
    CommandBase::drivetrain->zeroDrive();
    autoCommand = (Command*)autoMode->GetSelected();
    //robot.justShootTheBall(Time.RightNow); //aww
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
	autoCommand->Cancel();
    compressor->Start();
    CommandBase::catapult->zeroWinch();
    CommandBase::drivetrain->zeroDrive();
  }

  /** Runs continously during teleop */
  virtual void TeleopPeriodic()
  {
    Scheduler::GetInstance()->Run();
    printf("L:%d S-R:%d W-L:%d E:%f D:%f\n", CommandBase::catapult->isInLow(), CommandBase::catapult->safeReload(), CommandBase::catapult->getWinchLimitSwitch(), CommandBase::catapult->winchEncoder->GetDistance(), CommandBase::drivetrain->getAbsoluteDistance());
  }

  virtual void TestPeriodic()
  {
    //printf("Switch readout: %f", CommandBase::catapult->getWinchLimitSwitch() ? 1.0f : 0.0f);
    //lw->Run();
  }
};

START_ROBOT_CLASS(CommandBasedRobot);

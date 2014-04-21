#include "WPILib.h"
#include "CommandBase.h"
#include "Commands/Command.h"
#include "Commands/AutonomousModeOneBall.h"
#include "Commands/AutonomousModeTwoBall.h"
#include "Commands/AutonomousModeFastOneBall.h"
#include "Commands/AutonomousModeRamGoal.h"
#include "Commands/AutonomousModeLowGoal.h"
#include "Commands/AutonomousDriveCommand.h"
#include "Commands/AutonomousModeCheesyBall.h"
#include "Subsystems/CatapultSubsystem.h"
#include "Libraries/CheesyVisionServer.h"
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
    autoMode = new SendableChooser();
    autoMode->AddDefault("One Ball", new AutonomousModeOneBall());
    autoMode->AddObject("Fast One Ball (preload)", new AutonomousModeFastOneBall());
    autoMode->AddObject("Deux Ball", new AutonomousModeTwoBall());
    autoMode->AddObject("Just Friggin Drive", new AutonomousDriveCommand(1.0f, 0.0f, 2.0));
    autoMode->AddObject("Ram the one point goal", new AutonomousModeRamGoal());
    autoMode->AddObject("Low Goal", new AutonomousModeLowGoal());
    autoMode->AddObject("Low Goal", new AutonomousModeChessyBall());
    SmartDashboard::PutData("Autonomous Mode", autoMode);;
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
    printf("L:%d S-R:%d W-L:%d E:%f D:%f T:%f\n", CommandBase::catapult->isInLow(), CommandBase::catapult->safeReload(), CommandBase::catapult->getWinchLimitSwitch(), CommandBase::catapult->winchEncoder->GetDistance(), CommandBase::drivetrain->getAbsoluteDistance(), CommandBase::oi->turn());
  }

  virtual void TestPeriodic()
  {
    //printf("Switch readout: %f", CommandBase::catapult->getWinchLimitSwitch() ? 1.0f : 0.0f);
    //lw->Run();
  }

  virtual void DisabledInit()
  {
    CheesyVisionServer *cheeseView = CheesyVisionServer::GetInstance();
    shooterArm->Disable();
    cheeseView->StartSamplingCounts();
    cheeseView->StartListening();
  }

  virtual void DisabledPeriodic()
  {
    CheesyVisionServer *cheeseView = CheesyVisionServer::GetInstance();
    
    SmartDashboard::PutNumber("CheeseLeft:", cheeseView->GetLeftStatus());
    SmartDashboard::PutNumber("CheeseRight:", cheeseView->GetRightStatus());
    SmartDashboard::PutNumber("CheeseLeft Count:", cheeseView->GetLeftCount());
    SmartDashboard::PutNumber("CheeseRight Count:", cheeseView->GetRightCount());
    SmartDashboard::PutNumber("CheeseTotal Count:", cheeseView->GetTotalCount());

    SmartDashboard::PutBoolean("Cheesy Connected:", cheeseView->HasClientConnection());
  }
};

START_ROBOT_CLASS(CommandBasedRobot);

#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;

	void RobotInit()
	{
		CommandBase::init();
		autonomousCommand = new ExampleCommand();
		lw = LiveWindow::GetInstance();
		//		stopPneumaticsCommand= new cmdStopPneumatics();

				//autonomousCommand= new AutoGrabTurnRZone();

				chooser= new SendableChooser();
				chooser->AddDefault("Grab Tote Spin Right Move to Auto Zone", new driveForwardAutonomous1());
				chooser->AddObject("Grab Tote Spin Left Move to Auto Zone", new AutoGrabTurnLZone());
				chooser->AddObject("Grab Trash Stack Spin Left Move to Auto Zone", new AutoGrabTrashStackTurnLZone());
				chooser->AddObject("stack all totees", new AutoGrabAllTotes());
				SmartDashboard::PutData("Autonomous Modes", chooser);

	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
			autonomousCommand=(Command *)chooser-> GetSelected();

			if (autonomousCommand != NULL)
				autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);


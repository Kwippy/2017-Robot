#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Commands/AutoLowBar.h"
#include "Commands/AutoPortcullis.h"
#include "Commands/AutoChevaldeFrise.h"
#include "Commands/AutoRamparts.h"
#include "Commands/AutoMoat.h"
#include "Commands/AutoDrawbridge.h"
#include "Commands/AutoSallyPort.h"
#include "Commands/AutoRockWall.h"
#include "Commands/AutoRoughTerrain.h"



class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	SendableChooser *chooser;

	void RobotInit()
	{
		CommandBase::init();
		autonomousCommand = new ExampleCommand();
		lw = LiveWindow::GetInstance();

		//		CommandBase::oi->getGyro()->SetSensitivity(.007);//.0125);
		//		CommandBase::oi->getGyro()->InitGyro();
		//		CommandBase::oi->getGyro()->Reset(); // Resets the gyro's heading

				CommandBase::oi->getGyro()->Calibrate();

		//		stopPneumaticsCommand= new cmdStopPneumatics();

				//autonomousCommand= new AutoGrabTurnRZone();

				chooser= new SendableChooser();


				chooser->AddDefault("Low Bar", new AutoLowBar());
				chooser->AddObject("Cheval de Frise", new AutoChevaldeFrise());
				chooser->AddObject("Portcullis", new AutoPortcullis());
				chooser->AddObject("Ramparts", new AutoRamparts());
				chooser->AddObject("Moat", new AutoMoat());
				chooser->AddObject("Drawbridge", new AutoDrawbridge());
				chooser->AddObject("SallyPort", new AutoSallyPort());
				chooser->AddObject("RockWall", new AutoRockWall());
				chooser->AddObject("Rough Terrain", new AutoRoughTerrain());


				SmartDashboard::PutData("Autonomous Modes", chooser);

	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		CommandBase::oi->getGyro()->Reset(); // Resets the gyro's heading
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

//START_ROBOT_CLASS(Robot);


#include "Chassis.h"
#include "../RobotMap.h"
#include "../CommandBase.h"
#include <Commands/cmdDriveWithJoysticks.h>
#include "RobotDrive.h"
#include "OI.h"


Chassis::Chassis() :	Subsystem("Chassis")
{

//Creating two new instances of motor controllers that dictate each side--------------------------------------------

	LeftTalon = new Talon(FRONT_LEFT_TALON);
	RightTalon = new Talon(FRONT_RIGHT_TALON);

//Robot drive based on a definition of the motor configuration of each motor controller for the wheels--------------

	robotDrive = new RobotDrive(LeftTalon, RightTalon);


//Creates a new instance of Accelerometer---------------------------------------------------------------------------

	accel = new BuiltInAccelerometer();

//Sets the max output of the drive system---------------------------------------------------------------------------

	robotDrive->SetSafetyEnabled(false);
	robotDrive->SetMaxOutput(.7);

}

void Chassis::InitDefaultCommand()
{
	// Set the default command for a subsystem here.----------------------------------------------------------------

		SetDefaultCommand(new cmdDriveWithJoysticks());
}


// Put methods for controlling this subsystem ----------------------------------------------------------------------
// here. Call these from Commands.----------------------------------------------------------------------------------


void Chassis::DriveWithJoystick(Joystick *stickL, Joystick *stickR)
{
	//Purpose:
	//Using the driver station joysticks to drive the robot.
	//Inputs:   Are Instances of the Joystick class.

	//Left stick is reversed because of the motor directions needed to make mecanum work properly.
	robotDrive->TankDrive(-(stickL->GetY()), (stickR->GetY()),false);	//stickR, stickL, true)

}



/*WE MAY LIKELY NEED TO USE SOMETHING SIMILAR TO THIS, JUST WITH TANK INSTEAD OF MECANUM

void Chassis::AutoDrive(float x, float y, float z)
{
	robotDrive->MecanumDrive_Cartesian(x, y, z, CommandBase::oi->getGyro()->GetAngle());
}

/*
void Chassis::DriveForwardAutonomous()
{
	//drives the robot forward at half speed
	robotDrive->MecanumDrive_Cartesian(0, .5, 0, CommandBase::oi->getGyro()->GetAngle());
}
void Chassis::DriveBackwardAutonomous()
{
	//drives the robot backward at half speed
	robotDrive->MecanumDrive_Cartesian(0, -.5, 0, CommandBase::oi->getGyro()->GetAngle());
}
void Chassis::SlideLeftAutonomous()
{
	//slides the robot left at half speed
	robotDrive->MecanumDrive_Cartesian(-.5, 0, 0, CommandBase::oi->getGyro()->GetAngle());
}
void Chassis::SlideRightAutonomous()
{
	//slides the robot right at half speed
	robotDrive->MecanumDrive_Cartesian(.5, 0, 0, CommandBase::oi->getGyro()->GetAngle());
}
*/

/*
void Chassis::StopAutonomous()
{
	//stops the motion of the robot
	robotDrive->MecanumDrive_Cartesian(0, 0, 0, CommandBase::oi->getGyro()->GetAngle());
}

*/

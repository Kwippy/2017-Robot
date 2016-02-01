#include "AngleShooter.h"
#include "../RobotMap.h"
#include "../CommandBase.h"
#include "OI.h"

AngleShooter::AngleShooter() :
		Subsystem("AngleShooter")
{
	AngleShooterTalon = new Talon(ANGLE_SHOOTER_TALON);
}
void AngleShooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.


void AngleShooter:: AngleShoot(float AngleShooterSpeed)
{
	// Purpose:
	//To climb the robot at a given climb speed
	//Inputs: climb - takes a floating point value from -1 to 1, with 1 indicating full speed and .5 half speed.
	AngleShooterTalon->Set(AngleShooterSpeed);
}


void AngleShooter::StopAngleShooter()
{

	//stops the motion of the robot
	AngleShooterTalon->Set(0,0);

}

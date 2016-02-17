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
	AngleShooterTalon->Set(AngleShooterSpeed);
}


void AngleShooter:: AngleShootTrajectory(float AngleShooterDegrees)
{
	float AngleShooterSpeed;
	float gain=0.005;

	while((((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072)<(AngleShooterDegrees-5) || ((((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072))>(AngleShooterDegrees+5))
	{
		AngleShooterSpeed=(gain*((AngleShooterDegrees)-(((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072)))+0.3;

		/*
		 * THIS IS UNNECESSARY USING OUR NEW FORMULA THAT INCORPORATES GAIN AND VARIABLE SPEED, leaving in until tested
		 *
		if((((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072)<AngleShooterDegrees)
		{
			AngleShooterTalon->Set(AngleShooterSpeed);
		}
		else
		{
			AngleShooterTalon->Set(-AngleShooterSpeed);
		}
		*/

	}

	AngleShooterTalon->Set(0);


}

void AngleShooter::StopAngleShooter()
{

	//stops the motion of the robot
	AngleShooterTalon->Set(0);

}

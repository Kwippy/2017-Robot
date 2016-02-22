#include "AngleShooter.h"
#include "../RobotMap.h"
#include "../CommandBase.h"
#include "OI.h"

AngleShooter::AngleShooter() :
Subsystem("AngleShooter")
{
	AngleShooterSRXTalon = new TalonSRX(ANGLE_SHOOTER_SRX_TALON);
	float gain=0.003;
	float backDriveGain=0.000001;
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
	AngleShooterSRXTalon->Set(AngleShooterSpeed);
}


void AngleShooter:: AngleShootTrajectory(float AngleShooterDegrees)
{
	float AngleShooterSpeed;
	float gain=0.003;
	float backDriveGain=0.000001;

	while((((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072)<(AngleShooterDegrees-1) || ((((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072))>(AngleShooterDegrees+1))
	{
		if((((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072)<AngleShooterDegrees)
		{
			AngleShooterSpeed=(gain*((((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072))-(AngleShooterDegrees))-0.2;
			AngleShooterSRXTalon->Set(AngleShooterSpeed);
		}
		else
		{
			AngleShooterSpeed=(gain*((((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072))-(AngleShooterDegrees))+0.2;
			AngleShooterSRXTalon->Set(AngleShooterSpeed);
		}
	}

	float AngleShooterBackDriveSpeed;

	if((((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072)>=180)
	{
		AngleShooterBackDriveSpeed= (backDriveGain*((((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072)-(180)))-1.0;
	}
	else
	{
		AngleShooterBackDriveSpeed= (backDriveGain*((((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072)-(180)))+1.0;
	}

	AngleShooterSRXTalon->Set(AngleShooterBackDriveSpeed);

	//	AngleShooterSRXTalon->Set(0);
}

void AngleShooter:: AngleShootTrajectoryShift(float AngleDegreeShift)
{
	float AngleShooterDegreesCurrently=(((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072);
	float AngleShooterDestination=(((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072) + AngleDegreeShift;
	float gain=0.003;
	float backDriveGain=0.000001;
	float AngleShooterShiftSpeed=0.4;
	float AngleShooterShiftBackDriveSpeed;


	while((((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072)<(AngleShooterDestination-0.5) || ((((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072))>(AngleShooterDestination+0.5))
	{
		AngleShooterSRXTalon->Set(AngleShooterShiftSpeed);

		/* I don't think this is necessary as the speed to move such a small amount does not need to be and maybe should not be variable.
		 *
		if((((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072)<AngleShooterDestination)
		{
			AngleShooterShiftSpeed=(gain*((((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072))-(AngleShooterDestination))-0.2;
			AngleShooterSRXTalon->Set(AngleShooterShiftSpeed);
		}
		else
		{
			AngleShooterShiftSpeed=(gain*((((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072))-(AngleShooterDestination))+0.2;
			AngleShooterSRXTalon->Set(AngleShooterShiftSpeed);
		}
		*/
	}


	if((((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072)>=180)
	{
		AngleShooterShiftBackDriveSpeed= (backDriveGain*((((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072)-(180)))-1.0;
	}
	else
	{
		AngleShooterShiftBackDriveSpeed= (backDriveGain*((((CommandBase::oi->getAngleShootEncoder()->GetVoltage())/0.001)*0.072)-(180)))+1.0;
	}

	AngleShooterSRXTalon->Set(AngleShooterShiftBackDriveSpeed);

	//	AngleShooterSRXTalon->Set(0);
}



void AngleShooter::StopAngleShooter()
{

	//stops the motion of the robot
	AngleShooterSRXTalon->Set(0);

}

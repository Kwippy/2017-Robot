#include "Shooter.h"
#include "../RobotMap.h"
#include "../CommandBase.h"
#include "OI.h"

Shooter::Shooter() :  Subsystem("Shooter")
{
	//Creating two new instances of motor controllers that dictate each side--------------------------------------------
	LeftShooterSRXTalon = new TalonSRX(LEFT_SHOOTER_SRX_TALON);
	RightShooterSRXTalon = new TalonSRX(RIGHT_SHOOTER_SRX_TALON);
	LoaderServo = new Servo(9);

}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.


void Shooter::Shoot(float shootSpeed)
{
	// Purpose:
	//To shoot the robot at a given fire speed
	//Inputs: fire - takes a floating point value from -1 to 1, with 1 indicating full speed and .5 half speed.
	if((CommandBase::ballShooter->getLoaderServo()->Get())>=0.45 && (CommandBase::ballShooter->getLoaderServo()->Get())<=0.55)
	{
		LeftShooterSRXTalon->Set(shootSpeed);
		RightShooterSRXTalon->Set(shootSpeed);
	}
	else
	{
		//Below doesnt matter, since it should always be at 0 anyways if the servo is in the up position.
		LeftShooterSRXTalon->Set(0,0);
		RightShooterSRXTalon->Set(0,0);
	}

}


void Shooter::StopShooter()
{

	//stops the motion of the robot
	LeftShooterSRXTalon->Set(0,0);
	RightShooterSRXTalon->Set(0,0);

}

void Shooter::LoadBall()
{

	float servoPosition=LoaderServo->Get();

	if(servoPosition>=0.45 && servoPosition<=0.55)
	{
		LoaderServo->Set(1);
	}
	else if(servoPosition>=0.90 && servoPosition<=1)
	{
		LoaderServo->Set(0.5);
	}
	else
	{
		LoaderServo->Set(0.5);
	}
}

void Shooter::ServoDownPosition()
{
	LoaderServo->Set(0.5);
}


void Shooter::ServoUp()
{
	float servoPosition=LoaderServo->Get();
	float newServoPosition=servoPosition+0.05;

	LoaderServo->Set(newServoPosition);

}

void Shooter::ServoDown()
{
	float servoPosition=LoaderServo->Get();
	float newNewServoPosition=servoPosition-0.05;

	LoaderServo->Set(newNewServoPosition);

}

Servo* Shooter::getLoaderServo()
{
	return LoaderServo;
}

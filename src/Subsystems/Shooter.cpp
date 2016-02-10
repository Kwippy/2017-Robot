#include "Shooter.h"
#include "../RobotMap.h"
#include "../CommandBase.h"
#include "OI.h"

Shooter::Shooter() :  Subsystem("Shooter")
{
	//Creating two new instances of motor controllers that dictate each side--------------------------------------------
	LeftShooterTalon = new Talon(LEFT_SHOOTER_TALON);
	RightShooterTalon = new Talon(RIGHT_SHOOTER_TALON);
	LoaderServo = new Servo(0);

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

	LeftShooterTalon->Set(shootSpeed);
	RightShooterTalon->Set(shootSpeed);
}

void Shooter::Feed()
{
	LeftShooterTalon->Set(-0.4);
	RightShooterTalon->Set(-0.4);
}

void Shooter::StopShooter()
{

	//stops the motion of the robot
	LeftShooterTalon->Set(0,0);
	RightShooterTalon->Set(0,0);

}

void Shooter::LoadBall()
{
	float servoPosition=LoaderServo->Get();

	if(servoPosition==1)
	{
		LoaderServo->Set(0);
		servoPosition=0;
	}
	else if(servoPosition==0)
	{
		LoaderServo->Set(1);
		servoPosition=1;
	}
	else
	{
		LoaderServo->Set(1);
		servoPosition=1;

	}
	}

}

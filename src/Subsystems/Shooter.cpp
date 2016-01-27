#include "Shooter.h"
#include "../RobotMap.h"
#include "../CommandBase.h"
#include "OI.h"

Shooter::Shooter() :  Subsystem("Shooter")
{
	//Creating two new instances of motor controllers that dictate each side--------------------------------------------
	ShooterTalon = new Talon(SHOOTER_TALON);

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
	ShooterTalon->Set(shootSpeed);
}


void Shooter::StopShooter()
{

	//stops the motion of the robot
	ShooterTalon->Set(0,0);

}

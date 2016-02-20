#include "Climber.h"
#include "../RobotMap.h"
#include "../CommandBase.h"
#include "OI.h"

Climber::Climber() :  Subsystem("Climber")
{
	//Creating two new instances of motor controllers that dictate each side--------------------------------------------
	ClimberSRXTalon = new TalonSRX(CLIMBER_SRX_TALON);

}

void Climber::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.


void Climber::Climb(float climbSpeed)
{
	// Purpose:
	//To climb the robot at a given climb speed
	//Inputs: climb - takes a floating point value from -1 to 1, with 1 indicating full speed and .5 half speed.
	ClimberSRXTalon->Set(climbSpeed);
}


void Climber::StopClimber()
{

	//stops the motion of the robot
	ClimberSRXTalon->Set(0,0);

}

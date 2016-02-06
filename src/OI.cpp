#include <Commands/cmdClimberExtend.h>
#include "OI.h"
#include "RobotMap.h"
//#include <Commands/cmdShootHigh.h>
//#include <Commands/cmdShooterOff.h>
#include <Commands/cmdClimberOff.h>
#include <Commands/cmdClimberRetract.h>
#include <Commands/cmdResetGyro.h>

OI::OI()
{

// Process operator interface input here.

//	Sensors
//creates a new instance of Gyro
	gyro = new ADXRS450_Gyro();

//ENCODERS-------------------------------------------------

	LeftEncoder = new Encoder(2,3,true);
	LeftEncoder->SetDistancePerPulse(0.075);
	RightEncoder= new Encoder(0,1,true);
	RightEncoder->SetDistancePerPulse(0.075);
	AngleShootEncoder = new Encoder(4,5, true);
	AngleShootEncoder->SetDistancePerPulse(0.075);


//XBOX CONTROLLER------------------------------------------

//	xboxController= new Joystick(XBOXCONTROLLER);






//LEFT JOYSTICK--------------------------------------------

	driveStickL = new Joystick(JOYSTICKLEFT);






//RIGHT JOYSTICK------------------------------------------

	driveStickR = new Joystick(JOYSTICKRIGHT);

//	shootHigh = new JoystickButton(driveStickR, );
//	shootHigh->WhenPressed(new cmdShootHigh());
//	shootHigh->WhenReleased(new cmdShooterOff());

	climberRetract = new JoystickButton(driveStickR, R_THUMB_BUTTON_DOWN_fCLIMBRETRACT);
	climberRetract->WhenPressed(new cmdClimberRetract());
	climberRetract->WhenReleased(new cmdClimberOff());

	climberExtend = new JoystickButton(driveStickR, R_THUMB_BUTTON_UP_fCLIMBEXTEND);
	climberExtend->WhenPressed(new cmdClimberExtend());
	climberExtend->WhenReleased(new cmdClimberOff());

	gyroReset= new JoystickButton(driveStickR, R_LEFT_SIDE_UP_fRESET_GYRO);
	gyroReset->WhenPressed(new cmdResetGyro());




}

//Will return the location of the data of the user input at the left joystick
Gyro* OI::getGyro()
{
	return gyro;
}


//ENCODERS--------------------------------------

Encoder* OI::getLeftEncoder()
{
	return LeftEncoder;
}
Encoder* OI::getRightEncoder()
{
	return RightEncoder;
}
Encoder* OI::getAngleShootEncoder()
{
	return AngleShootEncoder;
}




//JOYSTICKS-----------------------------------------

Joystick* OI::getDriveStickL()
{
	return driveStickL;
}

Joystick* OI::getDriveStickR()
{
	return driveStickR;
}

/*
Joystick* OI::getControllerXbox()
{
	return xboxController;
}
*/

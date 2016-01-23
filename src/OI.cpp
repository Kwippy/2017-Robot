#include "OI.h"
#include "RobotMap.h"
#include <Commands/cmdShootHigh.h>

OI::OI()
{

// Process operator interface input here.

//ENCODERS-------------------------------------------------

	LeftEncoder = new Encoder(2,3,true);
	LeftEncoder->SetDistancePerPulse(0.075);
	RightEncoder= new Encoder(0,1,true);
	RightEncoder->SetDistancePerPulse(0.075);


//XBOX CONTROLLER------------------------------------------

	xboxController= new Joystick(XBOXCONTROLLER);






//LEFT JOYSTICK--------------------------------------------

	driveStickL = new Joystick(JOYSTICKLEFT);






//RIGHT JOYSTICK------------------------------------------

	driveStickR = new Joystick(JOYSTICKRIGHT);

	shootHigh = new JoystickButton(driveStickR, R_THUMB_BUTTON_DOWN_fSHOOTHIGH);
	shootHigh->WhenPressed(new cmdShootHigh());





}

//Will return the location of the data of the user input at the left joystick


//ENCODERS--------------------------------------

Encoder* OI::getLeftEncoder()
{
	return LeftEncoder;
}
Encoder* OI::getRightEncoder()
{
	return RightEncoder;
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

Joystick* OI::getControllerXbox()
{
	return xboxController;
}

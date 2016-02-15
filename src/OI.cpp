#include <Commands/cmdClimberExtend.h>
#include "OI.h"
#include "RobotMap.h"
#include <Commands/cmdShootHigh.h>
#include <Commands/cmdShooterOff.h>
#include <Commands/cmdClimberOff.h>
#include <Commands/cmdClimberRetract.h>
#include <Commands/cmdResetGyro.h>
#include <Commands/cmdgrpLoadandShoot.h>
#include <Commands/cmdFeedBall.h>
#include <Commands/cmdLoadBallServo.h>
#include <Commands/cmdTestServoUp.h>
#include <Commands/cmdTestServoDown.h>
#include <iostream>
#include <fstream>

using namespace std;


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
	AngleShootEncoder = new AnalogInput(3);



//XBOX CONTROLLER------------------------------------------

//	xboxController= new Joystick(XBOXCONTROLLER);






//LEFT JOYSTICK--------------------------------------------

	driveStickL = new Joystick(JOYSTICKLEFT);

	feedBall = new JoystickButton(driveStickL, L_THUMB_BUTTON_LEFT_fFEEDBALL);
	feedBall->WhenPressed(new cmdFeedBall());
	feedBall->WhenReleased(new cmdShooterOff());

	shootHigh = new JoystickButton(driveStickL, L_THUMB_BUTTON_RIGHT_fSHOOTHIGH);
	shootHigh->WhenPressed(new cmdShootHigh());
	shootHigh->WhenReleased(new cmdShooterOff());

	loadBall = new JoystickButton(driveStickL, L_THUMB_BUTTON_DOWN_fLOADBALL);
	loadBall->WhenPressed(new cmdLoadBallServo());

	testServoUp = new JoystickButton(driveStickL, L_LEFT_SIDE_UP_fTESTSERVOUP);
	testServoUp->WhenPressed(new cmdTestServoUp());

	testServoDown = new JoystickButton(driveStickL, L_LEFT_SIDE_DOWN_fTESTSERVODOWN);
	testServoDown->WhenPressed(new cmdTestServoDown());

	shootBall = new JoystickButton(driveStickL, L_THUMB_BUTTON_UP_fSHOOTBALL);
	shootBall->WhenPressed(new cmdgrpLoadandShoot());


//RIGHT JOYSTICK------------------------------------------

	driveStickR = new Joystick(JOYSTICKRIGHT);

	climberRetract = new JoystickButton(driveStickR, R_THUMB_BUTTON_DOWN_fCLIMBRETRACT);
	climberRetract->WhenPressed(new cmdClimberRetract());
	climberRetract->WhenReleased(new cmdClimberOff());

	climberExtend = new JoystickButton(driveStickR, R_THUMB_BUTTON_UP_fCLIMBEXTEND);
	climberExtend->WhenPressed(new cmdClimberExtend());
	climberExtend->WhenReleased(new cmdClimberOff());

	gyroReset= new JoystickButton(driveStickR, R_LEFT_SIDE_UP_fRESET_GYRO);
	gyroReset->WhenPressed(new cmdResetGyro());




}


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
AnalogInput* OI::getAngleShootEncoder()
{
	return AngleShootEncoder;
}
bool OI::setVisionNumbers()
{
	string line;
	string line2;
	ifstream myfile;
	myfile.open("FILENAMEHERE.txt");
	if(myfile.is_open())
	{
		float VisionAngle=0;
		float VisionDistance=0;
		getline(myfile, line);
		VisionAngle=stof(line);
		getline(myfile, line2);
		VisionDistance=stof(line2);
		myfile.close();
		return false;
	}
	else
		return true;
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

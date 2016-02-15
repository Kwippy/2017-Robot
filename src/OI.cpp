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
#include <Commands/cmdAngleShooterTrajectorySet.h>
#include <Commands/cmdAngleShooterMove.h>
#include <Commands/cmdStopAngleShooter.h>


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

	angleTrajectoryMove = new JoystickButton(driveStickL, L_RIGHT_SIDE_DOWN_fSETANGLETRAJECTORY);
	angleTrajectoryMove->WhenPressed(new cmdAngleShooterTrajectorySet(180));

	angleShooterUp = new JoystickButton(driveStickR, R_RIGHT_SIDE_UP_fANGLESHOOTERUP);
	angleShooterUp->WhenPressed(new cmdAngleShooterMove(0.2));
	angleShooterUp->WhenReleased(new cmdStopAngleShooter());

	angleShooterDown = new JoystickButton(driveStickR, R_RIGHT_SIDE_DOWN_fANGLESHOOTERDOWN);
	angleShooterDown->WhenPressed(new cmdAngleShooterMove(-0.2));
	angleShooterDown->WhenReleased(new cmdStopAngleShooter());

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

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
#include <Commands/cmdAngleShooterTrajectoryShift.h>
#include <Commands/cmdMoveClimberPiston.h>
#include <Commands/cmdAngleShooterPreventBackdrive.h>



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

	feedBall = new JoystickButton(driveStickL, L_THUMB_BUTTON_DOWN_fFEEDBALL);
	feedBall->WhenPressed(new cmdFeedBall(-0.6));
	feedBall->WhenReleased(new cmdShooterOff());


	spitBall = new JoystickButton(driveStickL, L_FRONT_SIDE_RIGHT_fSPITBALL);
	spitBall->WhenPressed(new cmdShootHigh(0.3));
	spitBall->WhenReleased(new cmdShooterOff());

	moveServoBall = new JoystickButton(driveStickL, L_FRONT_SIDE_LEFT_fMOVESERVOBALL);
	moveServoBall->WhenPressed(new cmdLoadBallServo());

	shootBall = new JoystickButton(driveStickL, L_THUMB_BUTTON_UP_fSHOOTBALL);
	shootBall->WhenPressed(new cmdgrpLoadandShoot());

//	angleTrajectorySetShoot = new JoystickButton(driveStickL, L_THUMB_BUTTON_RIGHT_fSHOOTPOSITION);
//	angleTrajectorySetShoot->WhenPressed(new cmdAngleShooterTrajectorySet(157));
//	angleTrajectorySetShoot->WhenReleased(new cmdAngleShooterPreventBackdrive());
//
//	angleTrajectorySetDown = new JoystickButton(driveStickL, L_THUMB_BUTTON_LEFT_fDOWNPOSITION);
//	angleTrajectorySetDown->WhenPressed(new cmdAngleShooterTrajectorySet(219));
//	angleTrajectorySetDown->WhenReleased(new cmdAngleShooterPreventBackdrive());
//
//	shiftShooterUp = new JoystickButton(driveStickL, L_LEFT_SIDE_UP_fSHIFTSHOOTERUP);
//	shiftShooterUp->WhenPressed(new cmdAngleShooterTrajectoryShift(-4));
//	shiftShooterUp->WhenReleased(new cmdAngleShooterPreventBackdrive());
//
//	shiftShooterDown = new JoystickButton(driveStickL, L_LEFT_SIDE_DOWN_fSHIFTSHOOTERDOWN);
//	shiftShooterDown->WhenPressed(new cmdAngleShooterTrajectoryShift(4));
//	shiftShooterDown->WhenReleased(new cmdAngleShooterPreventBackdrive());
//
//	shiftShooterUpSlightly = new JoystickButton(driveStickL, L_RIGHT_SIDE_UP_fSHIFTSHOOTERUPSLIGHTLY);
//	shiftShooterUpSlightly->WhenPressed(new cmdAngleShooterTrajectoryShift(-1));
//	shiftShooterUpSlightly->WhenReleased(new cmdAngleShooterPreventBackdrive());
//
//	shiftShooterDownSlightly = new JoystickButton(driveStickL, L_RIGHT_SIDE_DOWN_fSHIFTSHOOTERDOWNSLIGHTLY);
//	shiftShooterDownSlightly->WhenPressed(new cmdAngleShooterTrajectoryShift(1));
//	shiftShooterDownSlightly->WhenReleased(new cmdAngleShooterPreventBackdrive());



	//RIGHT JOYSTICK------------------------------------------

	driveStickR = new Joystick(JOYSTICKRIGHT);

	climberRetract = new JoystickButton(driveStickR, R_THUMB_BUTTON_DOWN_fCLIMBRETRACT);
	climberRetract->WhenPressed(new cmdClimberRetract());
	climberRetract->WhenReleased(new cmdClimberOff());

	climberExtend = new JoystickButton(driveStickR, R_THUMB_BUTTON_UP_fCLIMBEXTEND);
	climberExtend->WhenPressed(new cmdClimberExtend());
	climberExtend->WhenReleased(new cmdClimberOff());

	gyroReset= new JoystickButton(driveStickR, R_FRONT_SIDE_LEFT_fRESETGYRO);
	gyroReset->WhenPressed(new cmdResetGyro());

	stopAngleShooter = new JoystickButton(driveStickR, R_FRONT_SIDE_RIGHT_FSTOPANGLESHOOTER);
	stopAngleShooter->WhenPressed(new cmdStopAngleShooter());

	angleShooterUp = new JoystickButton(driveStickR, R_RIGHT_SIDE_UP_fANGLESHOOTERUP);
	angleShooterUp->WhenPressed(new cmdAngleShooterMove(0.8));
	angleShooterUp->WhenReleased(new cmdStopAngleShooter());
	//angleShooterUp->WhenReleased(new cmdAngleShooterPreventBackdrive());

	angleShooterDown = new JoystickButton(driveStickR, R_RIGHT_SIDE_DOWN_fANGLESHOOTERDOWN);
	angleShooterDown->WhenPressed(new cmdAngleShooterMove(-0.8));
	angleShooterDown->WhenReleased(new cmdStopAngleShooter());
	//angleShooterDown->WhenReleased(new cmdAngleShooterPreventBackdrive());

	testServoUp = new JoystickButton(driveStickR, R_LEFT_SIDE_UP_fTESTSERVOUP);
	testServoUp->WhenPressed(new cmdShootHigh(0.8));
	testServoUp->WhenReleased(new cmdShooterOff());


	testServoDown = new JoystickButton(driveStickR, R_LEFT_SIDE_DOWN_fTESTSERVODOWN);
	testServoDown->WhenPressed(new cmdFeedBall(-0.8));
	testServoDown->WhenReleased(new cmdShooterOff());

	moveClimberPistonUp = new JoystickButton(driveStickR, R_THUMB_BUTTON_RIGHT_fPISTONEXTEND);
	moveClimberPistonUp->WhenPressed(new cmdMoveClimberPiston(1));

	moveClimberPistonDown = new JoystickButton(driveStickR, R_THUMB_BUTTON_LEFT_PISTONRETRACT);
	moveClimberPistonDown->WhenPressed(new cmdMoveClimberPiston(-1));


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

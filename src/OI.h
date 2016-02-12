#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:

	Joystick *driveStickR, *driveStickL;
	ADXRS450_Gyro *gyro;

public:
	OI();

//Sensors------------------------------------------------------

	Gyro* getGyro();
	Encoder *LeftEncoder, *RightEncoder, *getLeftEncoder(), *getRightEncoder();
	AnalogInput *AngleShootEncoder, *getAngleShootEncoder();
//Left Joystick------------------------------------------------

	Joystick* getDriveStickL();
	JoystickButton *feedBall, *loadBall, *shootBall, *testServoUp, *testServoDown;

//Right JoyStick-----------------------------------------------

	Joystick* getDriveStickR();
	JoystickButton *shootHigh;
	JoystickButton *climberExtend, *climberRetract;
	JoystickButton *gyroReset;


//XBOX Controller----------------------------------------------

	Joystick* getControllerXbox();


};

#endif

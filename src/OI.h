#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:

	Joystick *driveStickR, *driveStickL;

public:
	OI();

//Sensors------------------------------------------------------

	Gyro* getGyro();
	Encoder *LeftEncoder, *RightEncoder, *getLeftEncoder(), *getRightEncoder();

//Left Joystick------------------------------------------------

	Joystick* getDriveStickL();

//Right JoyStick-----------------------------------------------

	Joystick* getDriveStickR();
//	JoystickButton *shootHigh;
	JoystickButton *climberExtend, *climberRetract;


//XBOX Controller----------------------------------------------

	Joystick* getControllerXbox();


};

#endif

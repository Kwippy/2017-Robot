#ifndef Chassis_H
#define Chassis_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Chassis: public Subsystem
{
private:

// It's desirable that everything possible under private except
// for methods that implement subsystem capabilities

	Talon *LeftTalon, *RightTalon;
	RobotDrive *robotDrive;
	Accelerometer *accel;


public:
	Chassis();
	void InitDefaultCommand();
	void DriveWithJoystick(Joystick *stickL, Joystick *stickR);
	void AutoDrive(float left, float right);
	void StopAutonomous();
};

#endif

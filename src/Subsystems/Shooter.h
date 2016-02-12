#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Shooter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	Talon *LeftShooterTalon, *RightShooterTalon;
	Servo *LoaderServo;


public:
	Shooter();
	void InitDefaultCommand();
	void Shoot(float shootSpeed);
	void StopShooter();
	void LoadBall();
	void ServoUp();
	void ServoDown();
	Servo* getLoaderServo();

};

#endif

#ifndef AngleShooter_H
#define AngleShooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class AngleShooter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon *AngleShooterTalon;
public:
	AngleShooter();
	void InitDefaultCommand();
	void AngleShoot(float AngleShooterSpeed);
	void AngleShootTrajectory(float AngleShooterSpeed, float AngleShooterDegrees);
	void StopAngleShooter();
};

#endif

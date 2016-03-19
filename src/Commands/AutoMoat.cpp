#include <Commands/AutoDriveTalonsFastBackwards.h>
#include "AutoMoat.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/AutoStop.h"
#include "Commands/cmdAngleShooterTrajectorySet.h"

AutoMoat::AutoMoat()
{
	AddSequential (new Delay(1));//waits one second
	//AddSequential (new cmdAngleShooterTrajectorySet(150)); //sets arm to known angle
	AddSequential (new AutoDriveTalonsFastBackwards());
	AddSequential (new Delay(4)); //stops after 4 seconds
	AddSequential (new AutoStop());

}

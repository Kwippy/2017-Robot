#include <Commands/AutoDriveTalonsFastBackwards.h>
#include "AutoRockWall.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/AutoStop.h"
#include "Commands/cmdAngleShooterTrajectorySet.h"
AutoRockWall::AutoRockWall()
{
	AddSequential (new Delay(1));//waits a second
	//AddSequential (new cmdAngleShooterTrajectorySet(150)); //sets arm up to known value
	AddSequential (new AutoDriveTalonsFastBackwards());
	AddSequential (new Delay(4));//drives for 4 seconds
	AddSequential (new AutoStop());
}

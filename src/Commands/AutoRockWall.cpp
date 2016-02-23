#include "AutoRockWall.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/AutoDriveTalons.h"
#include "Commands/AutoStop.h"
#include "Commands/cmdAngleShooterTrajectorySet.h"
AutoRockWall::AutoRockWall()
{
	AddSequential (new Delay(1));//waits a second
	AddSequential (new cmdAngleShooterTrajectorySet(155)); //sets arm up to known value
	AddSequential (new AutoDriveTalons(-0.5, -0.5, -0.5, -0.5)); //drives backwards at 50% speed
	AddSequential (new Delay(4));//drives for 4 seconds
	AddSequential (new AutoStop());
}

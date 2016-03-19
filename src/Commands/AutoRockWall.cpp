#include <Commands/AutoDriveTalonsReallyFastBackwards.h>
#include "AutoRockWall.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/AutoStop.h"
#include "Commands/cmdAngleShooterTrajectorySet.h"
AutoRockWall::AutoRockWall()
{
	//drives over backwards
		AddSequential (new Delay(1)); //waits a second
		//AddSequential (new cmdAngleShooterTrajectorySet(150));//sets arm up in known position
		AddSequential (new AutoDriveTalonsReallyFastBackwards());
		AddSequential (new Delay(3));//drives for 4 seconds
		AddSequential (new AutoStop());
}

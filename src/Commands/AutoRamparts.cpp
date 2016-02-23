#include "AutoRamparts.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/AutoDriveTalons.h"
#include "Commands/AutoStop.h"
#include "Commands/cmdAngleShooterTrajectorySet.h"

AutoRamparts::AutoRamparts()
{
	//drives over backwards
		AddSequential (new Delay(1)); //waits a second
		AddSequential (new cmdAngleShooterTrajectorySet(155));//sets arm up in known position
		AddSequential (new AutoDriveTalons(-0.5, -0.5, -0.5, -0.5));//drives backwards over obstacle
		AddSequential (new Delay(4));//drives for 4 seconds
		AddSequential (new AutoStop());

}

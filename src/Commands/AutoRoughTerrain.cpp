#include <Commands/AutoDriveTalonsFastBackwards.h>
#include "AutoRoughTerrain.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/AutoStop.h"
#include "Commands/cmdAngleShooterTrajectorySet.h"

AutoRoughTerrain::AutoRoughTerrain()
{
	AddSequential (new Delay(1)); //waits a second
	//AddSequential (new cmdAngleShooterTrajectorySet(150)); //sets angle up at known value
	AddSequential (new AutoDriveTalonsFastBackwards());
	AddSequential (new Delay(4)); //drives for 4 seconds
	AddSequential (new AutoStop());

}

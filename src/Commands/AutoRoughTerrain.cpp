#include "AutoRoughTerrain.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/AutoDriveTalons.h"
#include "Commands/AutoStop.h"
#include "Commands/cmdAngleShooterTrajectorySet.h"

AutoRoughTerrain::AutoRoughTerrain()
{
	AddSequential (new Delay(1)); //waits a second
	AddSequential (new cmdAngleShooterTrajectorySet(160)); //sets angle up at known value
	AddSequential (new AutoDriveTalons(-0.5, -0.5, -0.5, -0.5)); //drives backwards at 50% speed
	AddSequential (new Delay(4)); //drives for 4 seconds
	AddSequential (new AutoStop());

}

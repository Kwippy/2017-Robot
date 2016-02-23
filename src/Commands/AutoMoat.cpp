#include "AutoMoat.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/AutoDriveTalons.h"
#include "Commands/AutoStop.h"
#include "Commands/cmdAngleShooterTrajectorySet.h"

AutoMoat::AutoMoat()
{
	AddSequential (new Delay(1));//waits one second
	AddSequential (new cmdAngleShooterTrajectorySet(160)); //sets arm to known angle
	AddSequential (new AutoDriveTalons(-0.5, -0.5, -0.5, -0.5)); //drives backwards
	AddSequential (new Delay(4)); //stops after 4 seconds
	AddSequential (new AutoStop());

}

#include "AutoChevaldeFrise.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/AutoDriveTalons.h"
#include "Commands/AutoStop.h"
//#include "Commands/cmdAngleShooterTrajectorySet.h"


AutoChevaldeFrise::AutoChevaldeFrise()
{
	AddSequential (new Delay(1));
//	AddSequential (new AngleShootTrajectory(90));
	AddSequential (new AutoDriveTalons(0.5, 0.5, 0.5, 0.5));
	AddSequential (new Delay(4));
	AddSequential (new AutoStop());

}

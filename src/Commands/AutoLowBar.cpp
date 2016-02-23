#include "AutoLowBar.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/AutoDriveTalons.h"
#include "Commands/AutoStop.h"
#include "Commands/cmdAngleShooterTrajectorySet.h"

AutoLowBar::AutoLowBar()
{
	AddSequential(new Delay(1));//waits 1 second to begin
	AddSequential (new cmdAngleShooterTrajectorySet(250));//puts arm down
	AddSequential (new AutoDriveTalons(-0.5, -0.5, -0.5, -0.5));//drives backwards at 50% speed
	AddSequential (new Delay(4));//drives for 4 seconds
	AddSequential (new AutoStop());
}

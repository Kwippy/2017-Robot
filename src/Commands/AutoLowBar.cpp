#include <Commands/AutoDriveTalonsSlowBackwards.h>
#include "AutoLowBar.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/AutoStop.h"
#include "Commands/cmdAngleShooterTrajectorySet.h"
#include "Commands/cmdAngleShooterMove.h"
#include "Commands/cmdStopAngleShooter.h"

AutoLowBar::AutoLowBar()
{
	AddSequential(new Delay(1));//waits 1 second to begin
	//AddSequential (new cmdAngleShooterTrajectorySet(219));//puts arm down
	AddSequential (new cmdAngleShooterMove(-0.6));
	AddSequential (new Delay(1));
	AddSequential (new cmdStopAngleShooter());
	AddSequential (new AutoDriveTalonsSlowBackwards());//drives backwards at 50% speed
	AddSequential (new Delay(6));//drives for 4 seconds
	AddSequential (new AutoStop());
}

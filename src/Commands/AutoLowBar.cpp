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
	AddSequential(new Delay(1));							//waits 1 second
	AddSequential (new cmdAngleShooterMove(-0.6));			//Moves shooter down
	AddSequential (new Delay(1));							//Waits one second
	AddSequential (new cmdStopAngleShooter());				//Stops shooter movement
	AddSequential (new AutoDriveTalonsSlowBackwards());		//drives backwards slowly
	AddSequential (new Delay(6));							//drives for 6 seconds
	AddSequential (new AutoStop());							//Stops
}

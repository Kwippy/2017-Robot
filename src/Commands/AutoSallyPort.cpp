#include <Commands/AutoDriveTalonsFastBackwards.h>
#include "AutoSallyPort.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/AutoStop.h"
#include "Commands/cmdAngleShooterTrajectorySet.h"

AutoSallyPort::AutoSallyPort()
{
	AddSequential (new Delay(1));
	AddSequential (new cmdAngleShooterTrajectorySet(150));
	AddSequential (new AutoDriveTalonsFastBackwards());
	AddSequential (new Delay(4));
	AddSequential (new AutoStop());
}

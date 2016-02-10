#include "cmdgrpLoadandShoot.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/cmdShootHigh.h"
#include "Commands/cmdShooterOff.h"
#include "Commands/cmdLoadBallServo.h"

cmdgrpLoadandShoot::cmdgrpLoadandShoot()
{

	AddSequential (new cmdShootHigh());
	AddSequential (new Delay(5));
	AddSequential (new cmdLoadBallServo());
	AddSequential (new Delay(3));
	AddSequential (new cmdShooterOff());
}

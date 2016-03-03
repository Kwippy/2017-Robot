#include "cmdgrpLoadandShoot.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/cmdShootHigh.h"
#include "Commands/cmdShooterOff.h"
#include "Commands/cmdServoDownPosition.h"
#include "Commands/cmdServoFirePosition.h"

cmdgrpLoadandShoot::cmdgrpLoadandShoot()
{
	//Unnecessary as the servo should always be in this position while the ball is in anyways, but just to be safe
	AddSequential (new cmdServoDownPosition());
	//Lets Servo move if necessary
	AddSequential (new Delay(0.5));

	//Spins up shooter motors
	AddSequential (new cmdShootHigh(0.4));
	AddSequential (new Delay(2));

	//Fires Ball
	AddSequential (new cmdServoFirePosition());

	//Lets the ball exit completely before shutting off Shooter
	AddSequential (new Delay(1));
	AddSequential (new cmdShooterOff());

	//Set Servo back to lower position
	AddSequential (new cmdServoDownPosition());

}

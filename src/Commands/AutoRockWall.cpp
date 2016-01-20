#include "AutoRockWall.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/AutoDrive.h"
AutoRockWall::AutoRockWall()
{
	AddSequential(new Delay(1));
}

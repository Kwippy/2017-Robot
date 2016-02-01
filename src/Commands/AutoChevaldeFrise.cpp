#include "AutoChevaldeFrise.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/AutoDrive.h"

AutoChevaldeFrise::AutoChevaldeFrise()
{
	AddSequential (new Delay(1));
	AddSequential (new AutoDrive(48));
}

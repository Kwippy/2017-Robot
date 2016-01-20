#include "AutoDrawbridge.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/AutoDrive.h"

AutoDrawbridge::AutoDrawbridge()
{
	AddSequential(new Delay(1));
}

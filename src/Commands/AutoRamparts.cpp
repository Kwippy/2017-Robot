#include "AutoRamparts.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/AutoDrive.h"

AutoRamparts::AutoRamparts()
{
	AddSequential (new Delay(1));
}

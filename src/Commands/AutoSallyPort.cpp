#include "AutoSallyPort.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/AutoDrive.h"

AutoSallyPort::AutoSallyPort()
{
	AddSequential(new Delay(1));
}

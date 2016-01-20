#include "AutoMoat.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/AutoDrive.h"

AutoMoat::AutoMoat()
{
	AddSequential(new Delay(1));
}

#include "AutoLowBar.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/AutoDrive.h"

AutoLowBar::AutoLowBar()
{
	AddSequential(new Delay(1));
}

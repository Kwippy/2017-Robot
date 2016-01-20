#include "AutoPortcullis.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"
#include "Commands/AutoDrive.h"

AutoPortcullis::AutoPortcullis()
{
	AddSequential (new Delay (1));
}

#ifndef AutoRamparts_H
#define AutoRamparts_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoRamparts: public CommandBase
{
public:
	AutoRamparts();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

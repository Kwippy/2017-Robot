#ifndef AutoSallyPort_H
#define AutoSallyPort_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoSallyPort: public CommandBase
{
public:
	AutoSallyPort();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

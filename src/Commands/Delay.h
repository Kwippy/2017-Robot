#ifndef Delay_H
#define Delay_H

#include "../CommandBase.h"
#include "WPILib.h"

class Delay: public CommandBase
{
public:
	Delay();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

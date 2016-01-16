#ifndef AutoChevaldeFrise_H
#define AutoChevaldeFrise_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoChevaldeFrise: public CommandBase
{
public:
	AutoChevaldeFrise();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

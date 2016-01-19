#ifndef AutoLowBar_H
#define AutoLowBar_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoLowBar: public CommandBase
{
public:
	AutoLowBar();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

#ifndef AutoDrawbridge_H
#define AutoDrawbridge_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoDrawbridge: public CommandBase
{
public:
	AutoDrawbridge();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

#ifndef AutoRockWall_H
#define AutoRockWall_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoRockWall: public CommandBase
{
public:
	AutoRockWall();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

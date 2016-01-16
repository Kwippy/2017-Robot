#ifndef AutoRoughTerrain_H
#define AutoRoughTerrain_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoRoughTerrain: public CommandBase
{
public:
	AutoRoughTerrain();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

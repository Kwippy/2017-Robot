#ifndef cmdShooter_H
#define cmdShooter_H

#include "../CommandBase.h"
#include "WPILib.h"

class cmdShootHigh: public CommandBase
{
private:

public:
	cmdShootHigh();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

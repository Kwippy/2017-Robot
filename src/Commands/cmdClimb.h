#ifndef cmdClimb_H
#define cmdClimb_H

#include "../CommandBase.h"
#include "WPILib.h"

class cmdClimb: public CommandBase
{
public:
	cmdClimb();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

#ifndef cmdFeedBall_H
#define cmdFeedBall_H

#include "../CommandBase.h"
#include "WPILib.h"

class cmdFeedBall: public CommandBase
{
public:
	cmdFeedBall();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

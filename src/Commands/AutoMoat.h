#ifndef AutoMoat_H
#define AutoMoat_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoMoat: public CommandBase
{
public:
	AutoMoat();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

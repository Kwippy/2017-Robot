#ifndef AutoPortcullis_H
#define AutoPortcullis_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoPortcullis: public CommandBase
{
public:
	AutoPortcullis();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

/*
 * DriveForwardAuto1.h
 *
 *  Created on: Jan 16, 2016
 *      Author: 182150
 */

#ifndef SRC_COMMANDS_DRIVEFORWARDAUTO1_H_
#define SRC_COMMANDS_DRIVEFORWARDAUTO1_H_

#include "../CommandBase.h"
#include "WPILib.h"

class AutoForward: public CommandBase
{
private:
	float distance;
public:
	AutoForward(float d);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif





#endif /* SRC_COMMANDS_DRIVEFORWARDAUTO1_H_ */

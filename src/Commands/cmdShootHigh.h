#ifndef cmdShooter_H
#define cmdShooter_H

#include "../CommandBase.h"
#include "WPILib.h"

class cmdShootHigh: public CommandBase
{
private:
	float shootSpeed;
public:
	cmdShootHigh(float ShootingSpeed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

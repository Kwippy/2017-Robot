#include "AutoDriveTalonsFastBackwards.h"

AutoDriveTalonsFastBackwards::AutoDriveTalonsFastBackwards()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(tankChassis);
}

// Called just before this Command runs the first time
void AutoDriveTalonsFastBackwards::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoDriveTalonsFastBackwards::Execute()
{
	tankChassis->AutoDriveTalons(-0.6, -0.6, -0.6, -0.6);

}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveTalonsFastBackwards::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void AutoDriveTalonsFastBackwards::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveTalonsFastBackwards::Interrupted()
{

}

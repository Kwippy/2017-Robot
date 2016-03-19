#include "AutoDriveTalonsFastForward.h"

AutoDriveTalonsFastForward::AutoDriveTalonsFastForward()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(tankChassis);

}

// Called just before this Command runs the first time
void AutoDriveTalonsFastForward::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoDriveTalonsFastForward::Execute()
{
	tankChassis->AutoDriveTalons(0.6, 0.6, 0.6, 0.6);

}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveTalonsFastForward::IsFinished()
{
	return true;
;
}

// Called once after isFinished returns true
void AutoDriveTalonsFastForward::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveTalonsFastForward::Interrupted()
{

}

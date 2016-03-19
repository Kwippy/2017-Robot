#include <Commands/AutoDriveTalonsSlowBackwards.h>

AutoDriveTalonsSlowBackwards::AutoDriveTalonsSlowBackwards()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(tankChassis);

}

// Called just before this Command runs the first time
void AutoDriveTalonsSlowBackwards::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoDriveTalonsSlowBackwards::Execute()
{
	tankChassis->AutoDriveTalons(-0.25, -0.25, -0.25, -0.25);

}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveTalonsSlowBackwards::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void AutoDriveTalonsSlowBackwards::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveTalonsSlowBackwards::Interrupted()
{

}

#include "cmdClimb.h"

cmdClimb::cmdClimb()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(robotClimber);
}

// Called just before this Command runs the first time
void cmdClimb::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void cmdClimb::Execute()
{
	robotClimber->Climb(0.3);
}

// Make this return true when this Command no longer needs to run execute()
bool cmdClimb::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void cmdClimb::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdClimb::Interrupted()
{

}

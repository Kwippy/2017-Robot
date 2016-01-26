#include <Commands/cmdShootHigh.h>

cmdShootHigh::cmdShootHigh()
{

	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(ballShooter);
}

// Called just before this Command runs the first time
void cmdShootHigh::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void cmdShootHigh::Execute()
{
	ballShooter->Shoot(0.3);
}

// Make this return true when this Command no longer needs to run execute()
bool cmdShootHigh::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void cmdShootHigh::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdShootHigh::Interrupted()
{

}

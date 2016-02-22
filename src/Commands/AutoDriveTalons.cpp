#include "AutoDriveTalons.h"

AutoDriveTalons::AutoDriveTalons(float FrontLeftSpeed, float BackLeftSpeed, float FrontRightSpeed,  float BackRightSpeed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(tankChassis);

	float FLTalonSpeed=FrontLeftSpeed;
	float BLTalonSpeed=BackLeftSpeed;
	float FRTalonSpeed=FrontRightSpeed;
	float BRTalonSpeed=BackRightSpeed;
}

// Called just before this Command runs the first time
void AutoDriveTalons::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoDriveTalons::Execute()
{
   tankChassis->AutoDriveTalons(FLTalonSpeed, BLTalonSpeed, FRTalonSpeed,  BRTalonSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveTalons::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void AutoDriveTalons::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveTalons::Interrupted()
{

}

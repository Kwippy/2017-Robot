#include "DataDisplay.h"
#include "../RobotMap.h"
#include "OI.h"
#include "../CommandBase.h"
#include <Commands/cmdDataDashboard.h>

DataDisplay::DataDisplay() : Subsystem("DataDisplay")
{

}

void DataDisplay::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
		SetDefaultCommand(new cmdDataDashboard());
}

// Put methods for controlling this subsystem---------------------------------------------------------------
// here. Call these from Commands.--------------------------------------------------------------------------


void  DataDisplay::DisplayAll()
{

	SmartDashboard::PutNumber("Left Encoder Speed:", CommandBase::oi->getLeftEncoder()->GetRate());
	SmartDashboard::PutNumber("Right Encoder Speed:", CommandBase::oi->getRightEncoder()->GetRate());
	SmartDashboard::PutNumber("Gyro: ", CommandBase::oi->getGyro()->GetAngle());

}

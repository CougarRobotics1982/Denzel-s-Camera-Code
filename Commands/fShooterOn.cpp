// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "fShooterOn.h"
fShooterOn::fShooterOn() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shooter);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void fShooterOn::Initialize() {
	count = 0;
	Robot::shooter->count = 0;
	//Robot::shooter->SetSpeed(.4);
}
// Called repeatedly when this Command is scheduled to run
void fShooterOn::Execute() {
	//if(count > 100)
	//{
		Robot::shooter->Enable();
		Robot::shooter->SetSetpoint(Robot::shooter->setPoint);
	//}
	
	if(count%10 == 0)
			printf("RPM: %f PID Input: %f Set Point: %d Angle: %f Output: %f\n", Robot::shooter->GetRPM(), Robot::shooter->ReturnPIDInput(), Robot::shooter->setPoint, Robot::platform->GetAngle(), Robot::shooter->output1);
		
		count++;
}
// Make this return true when this Command no longer needs to run execute()
bool fShooterOn::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void fShooterOn::End() {
	Robot::shooter->Disable();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void fShooterOn::Interrupted() {
	Robot::shooter->Disable();
}

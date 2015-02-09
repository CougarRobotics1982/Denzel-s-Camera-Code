// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "aRight_Back.h"
#include "fShoot.h"
aRight_Back::aRight_Back() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::autonomous);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	shoot = new fShoot();
}
// Called just before this Command runs the first time
void aRight_Back::Initialize() {
	Robot::sensors->gyro->Reset();
	go = false;
}
// Called repeatedly when this Command is scheduled to run
void aRight_Back::Execute() {
	counter ++;
	timer = counter/50.0f;
	Robot::shooter->SetSpeed(.9);
	//shoot the frisbees 4 times
	if(timer == 2)
		shoot->Start();
	if(timer == 3.5)
		shoot->Start();
	if(timer == 5)
		shoot->Start();
	if(timer == 6.5)
		shoot->Start();
	//after you finish shooting go back
	if(timer >6.8 && timer < 8)
		Robot::driveTrain->MecanumDrive(-.3,0,0);
	//after you finish shooting turn around
	if(timer >= 8  && go == false)
	{
		if(Robot::sensors->gyro->GetAngle()< 0.5)
			Robot::driveTrain->SetSpeed(0,.25);
		else
			go = true;
	}
	//when you've turned around go to get frisbees
	if(go == true)
		Robot::driveTrain->MecanumDrive(0,0.3,0);
	
	
}
// Make this return true when this Command no longer needs to run execute()
bool aRight_Back::IsFinished() {
	if(timer > 15)
		return true;
	else		
		return false;
}
// Called once after isFinished returns true
void aRight_Back::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void aRight_Back::Interrupted() {
}

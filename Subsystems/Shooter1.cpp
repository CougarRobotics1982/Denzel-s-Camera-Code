// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Shooter1.h"
#include "../Robotmap.h"
#include "../Commands/ShooterOn1.h"
#include "../Commands/pTilt1.h"
Shooter1::Shooter1() : Subsystem("Shooter1") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	done = (0);
	
}
    
void Shooter1::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new ShooterOn1());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	
	speed = 0;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Shooter1::PresetInit() {
	Robot::shooter1->speed = 0;
	count = 0;
	done = 0;
}
void Shooter1::PresetExecute(float speed, float angle)
{
	if(count == 0 && rpm < 1500 && angle != 0)
	{
		Robot::platform->angle = angle;
		tilt = new pTilt1();
		tilt->Start();
		
		printf("Starting tilt1: %f\n", rpm);
		count++;
	}
	else if(!tilt->IsRunning() && count > 0)
	{
		Robot::shooter1->speed = speed;
		done++;
		
		printf("Done Motor speed: %f\n", speed);
		count++;
	}
	
	
	
}
bool Shooter1::PresetIsFinished()
{
	if(done>100)
	{
		printf("PRESET FINISHED");
		return true;
	}
	else
		return false;
	//return (done>50);
}

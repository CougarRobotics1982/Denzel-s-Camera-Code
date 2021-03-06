// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
/**
 *
 *
 * @author ExampleAuthor
 */
class Autonomous: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	DigitalInput* left_Right;
	DigitalInput* side_Back;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Autonomous();
	void InitDefaultCommand();
	void AutonomousInit(bool side);
	void AutonomousExecute();
	bool AutonomousIsFinished();
	Command* preset;
	Command* shoot;
	int shoot_count;
	bool done;
	int scount;
	bool armed;
};
#endif

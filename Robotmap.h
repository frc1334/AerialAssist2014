#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

#define LEFT_TALON_1			-1
#define LEFT_TALON_2			-1
#define LEFT_TALON_3			-1
#define RIGHT_TALON_1			-1
#define RIGHT_TALON_2			-1
#define RIGHT_TALON_3			-1

#define WINCH_TALON_1			-1
#define WINCH_TALON_2			-1
#define PICK_TALON				-1

#define DRIVE_SOLENOID			-1

#define TILT_SOLENOID			-1
#define MIDLOCK_SOLENOID		-1
#define WINCH_GEARBOX_SOLENOID	-1
#define PICK_STATE_SOLENOID		-1


#endif

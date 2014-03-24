#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// Double slashes indicate unassigned ports

#define LEFT_TALON_1				4
#define LEFT_TALON_2				5
#define RIGHT_TALON_1				6
#define RIGHT_TALON_2				7
#define PICKUP_TALON				3
#define WINCH_TALON_1				2
#define WINCH_TALON_2				1

#define COMPRESSOR_SWITCH			14
#define WINCH_ENCODER_A				1
#define WINCH_ENCODER_B				2
#define WINCH_SWITCH				3
#define DRIVE_LEFT_ENCODER_A		10
#define DRIVE_LEFT_ENCODER_B		11
#define DRIVE_RIGHT_ENCODER_A		12
#define DRIVE_RIGHT_ENCODER_B		13

#define DRIVE_SOLENOID				2
#define LATCH_SOLENOID_A			7
#define LATCH_SOLENOID_B			8
#define LAUNCHER_OPEN_SOLENOID		4
#define ROLLER_EXTEND_SOLENOID		5
//#define LAUNCHER_MIDLOCK_SOLENOID	1
#define LAUNCHER_TILT_SOLENOID		3
#define SIDE_CONSTRAINT_SOLENOID	6

#define COMPRESSOR_RELAY			1

#endif

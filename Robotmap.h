#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// Double slashes indicate unassigned ports

#define LEFT_TALON_1				1
#define LEFT_TALON_2				2
#define RIGHT_TALON_1				3
#define RIGHT_TALON_2				4
#define PICKUP_TALON				5
#define WINCH_TALON_1				6
#define WINCH_TALON_2				7

#define COMPRESSOR_SWITCH			1
#define WINCH_ENCODER_A				10
#define WINCH_ENCODER_B				11
#define WINCH_SWITCH				4
#define WINCH_LOADED_SWITCH			5

#define DRIVE_SOLENOID				1
#define LATCH_SOLENOID				2
#define LAUNCHER_OPEN_SOLENOID		6
#define ROLLER_EXTEND_SOLENOID		4
#define LAUNCHER_MIDLOCK_SOLENOID	5
#define LAUNCHER_TILT_SOLENOID		3
#define SIDE_CONSTRAINT_SOLENOID	7

#define COMPRESSOR_RELAY			1

#endif

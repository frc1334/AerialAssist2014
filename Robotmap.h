#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

#define LEFT_TALON_1			1
#define LEFT_TALON_2			2
#define LEFT_TALON_3			5//
#define RIGHT_TALON_1			3
#define RIGHT_TALON_2			4
#define RIGHT_TALON_3			6//

#define WINCH_TALON_1			7//
#define WINCH_TALON_2			8//
#define PICK_TALON				9//

#define DRIVE_SOLENOID			1//

#define TILT_SOLENOID			2//
#define MIDLOCK_SOLENOID		3//
#define WINCH_GEARBOX_SOLENOID	4//
#define PICK_STATE_SOLENOID		5//


#endif

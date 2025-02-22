/**
 * Motor interface
 *
 * This file contains functions for controlling the movement of the bot.
 */

#ifndef MOTOR_H
#define MOTOR_H

#include "types.h"

/// @brief Returns whether the motor is ready and `motor_pulse()` can be invoked.
/// @return 1 if the motors are ready, 0 otherwise.
uint8_t is_motor_ready();

/// @brief Waits for the motor to become ready.
inline static void motor_wait()
{
    while (!is_motor_ready())
    {
        // Busy-wait loop
    }
}

/// @brief Sends a pulse to the motors.
/// @param left Direction of the left motor, 1 or -1.
/// @param right Direction of the right motor, 1 or -1.
void motor_pulse(int8_t left, int8_t right);

/// @brief Moves the bot one tile forward in the direction it's facing.
inline static void motor_step_fw()
{
    motor_pulse(1, 1);
}

/// @brief Moves the bot one tile away (backward) from the direction it's facing.
inline static void motor_step_bw()
{
    motor_pulse(-1, -1);
}

/// @brief Turns the bot to its left (i.e. counterclockwise).
inline static void motor_turn_left()
{
    motor_pulse(-1, 1);
}

/// @brief Turns the bot to its right (i.e. clockwise).
inline static void motor_turn_right()
{
    motor_pulse(1, -1);
}

/// @brief Turns the bot around.
inline static void motor_turn_around()
{
    motor_turn_left();
    motor_wait();
    motor_turn_left();
}

#endif // MOTOR_H
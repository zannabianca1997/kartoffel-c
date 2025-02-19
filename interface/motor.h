#ifndef MOTOR_H
#define MOTOR_H

// Checks if the motor is ready
uint8_t is_motor_ready();
// Waits for the motor to become ready
void motor_wait();
// Sends a pulse to the motors
void motor_pulse(int8_t left, int8_t right);
// Moves the bot one tile forward
void motor_step_fw();
// Moves the bot one tile backward
void motor_step_bw();
// Turns the bot left (counterclockwise)
void motor_turn_left();
// Turns the bot right (clockwise)
void motor_turn_right();

#endif // MOTOR_H
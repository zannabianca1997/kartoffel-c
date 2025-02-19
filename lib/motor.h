#ifndef MOTOR_H
#define MOTOR_H

#include "lib.h"

// Checks if the motor is ready
uint8_t is_motor_ready() {
    return rdi(MEM_MOTOR, 0) == 1;
}

// Waits for the motor to become ready
void motor_wait() {
    while (!is_motor_ready()) {
        // Busy-wait loop
    }
}

// Sends a pulse to the motors
void motor_pulse(int8_t left, int8_t right) {
    wri(MEM_MOTOR, 0, cmd(0x01, (uint8_t)left, (uint8_t)right, 0x00));
}

// Moves the bot one tile forward
void motor_step_fw() {
    motor_pulse(1, 1);
}

// Moves the bot one tile backward
void motor_step_bw() {
    motor_pulse(-1, -1);
}

// Turns the bot left (counterclockwise)
void motor_turn_left() {
    motor_pulse(-1, 1);
}

// Turns the bot right (clockwise)
void motor_turn_right() {
    motor_pulse(1, -1);
}

void motor_turn_around() {
    motor_pulse(1, -1);
    motor_wait();
    motor_pulse(1, -1);
}


#endif // MOTOR_H

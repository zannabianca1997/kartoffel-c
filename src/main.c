#include "motor.h"

int main(void)
{
  while (1)
  {
    motor_wait();
    motor_step_fw();

    motor_wait();
    motor_step_fw();

    motor_wait();
    motor_step_fw();

    motor_wait();
    motor_turn_right();
  }
}
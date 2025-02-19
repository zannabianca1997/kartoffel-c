#include "lib/serial.h"
#include "lib/motor.h"
#include "lib/radar.h"
#include "lib/arm.h"

int main(void)
{
  serial_write_str("War Crimes Committer has entered the chat!\n");
  motor_wait();
  motor_step_fw();
  while (1) {
    radar_wait();
    RadarScan scan = radar_scan_3x3();
    char front = radar_scan_at(&scan, 3, 0, -1);
    char left = radar_scan_at(&scan, 3, -1, 0);
    char right = radar_scan_at(&scan, 3, 1, 0);
    if (front == '.') {
      motor_wait();
      motor_step_fw();
    } else if (front == '@') {
      motor_wait();
      motor_step_fw();
      arm_wait();
      arm_stab();
    } else if (left == '.') {
      motor_wait();
      motor_turn_left();
      motor_wait();
      motor_step_fw();
    } else if (right == '.') {
      motor_wait();
      motor_turn_right();
      motor_wait();
      motor_step_fw();
    }
  }
}

__attribute__((naked, section(".init")))
void _start()
{
    __asm__ volatile (
        "la sp, _stack_end\n"
        "jal main\n"
        "ebreak\n"
    );
}
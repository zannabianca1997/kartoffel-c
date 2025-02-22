#include "mem.h"
#include "types.h"
#include "motor.h"

uint8_t is_motor_ready()
{
    return rdi(MEM_MOTOR, 0) == 1;
}

/// @details
/// Outcome depends on the parameters - legal combinations are:
///
/// - `(1, 1)` - bot drives forward,
/// - `(-1, -1)` - bot drives backward,
/// - `(-1, 1)` - bot turns left (counterclockwise),
/// - `(1, -1)` - bot turns right (clockwise).
///
/// Other values will cause the CPU to crash.
///
/// Note that this is a low-level function - for convenience you'll most likely
/// want to use one of:
///
/// - `motor_step_fw()`,
/// - `motor_step_bw()`,
/// - `motor_turn_left()`,
/// - `motor_turn_right()`.
///
/// # Cooldown
///
/// Depends on the parameters, see:
///
/// - `motor_step_fw()`,
/// - `motor_step_bw()`,
/// - `motor_turn_left()`,
/// - `motor_turn_right()`,
void motor_pulse(int8_t left, int8_t right)
{
    wri(MEM_MOTOR, 0, cmd(0x01, (uint8_t)left, (uint8_t)right, 0x00));
}

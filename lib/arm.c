
#include "mem.h"
#include "types.h"
#include "arm.h"

uint8_t is_arm_ready()
{
    return rdi(MEM_ARM, 0) == 1;
}

/// @details
/// If there's nobody there, nothing happens (but the cooldown is still
/// applied).
///
/// # Cooldown
///
/// ```text
/// 60_000 +- 15% ticks (~930 ms)
/// ```
void arm_stab()
{
    wri(MEM_ARM, 0, cmd(0x01, 0x00, 0x00, 0x00));
}

/// @details
/// Picks the object in front of you and puts it into the inventory under the
/// zeroth index, shifting previously-picked objects into further indices.
///
/// (that is: if you had object at idx=0, picking a new object would shift this
/// already-picked object into idx=1, and then the newly-picked object would
/// appear at idx=0.)
///
/// If there's no object in front of you or you don't have any more space in the
/// inventory, nothing happens (but the cooldown is still applied).
///
/// # Cooldown
///
/// ```text
/// 60_000 +- 15% ticks (~930 ms)
/// ```
void arm_pick()
{
    wri(MEM_ARM, 0, cmd(0x02, 0x00, 0x00, 0x00));
}

/// @details
/// Takes object from the inventory and drops it in front of you, shifting
/// following objects into their previous indices.
///
/// (that is: if you had objects at idx=0, idx=1 and idx=2, then dropping the
/// object at idx=1 would move object idx=2 back to idx=1.)
///
/// If you don't have object with given index or the object can't be placed in
/// front of you (e.g. because you're looking at a wall), nothing happens (but
/// the cooldown is still applied).
///
/// # Cooldown
///
/// ```text
/// 60_000 +- 15% ticks (~930 ms)
/// ```
void arm_drop(uint8_t idx)
{
    wri(MEM_ARM, 0, cmd(0x03, idx, 0x00, 0x00));
}

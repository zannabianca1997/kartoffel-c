#include "serial.h"
#include "types.h"
#include "mem.h"

/// @details Serial port is a circular buffer with capacity for 256 UTF-8 characters -
/// writing 257th character shifts all the previous characters, removing the
/// first one.
void serial_write(char ch)
{
    *MEM_SERIAL = (unsigned int)ch;
}

/// @details In this mode all characters written into the serial port get buffered until
/// you call `serial_flush()` or `serial_clear()`.
///
/// This comes handy for animations, interactive UIs etc., since it prevents
/// seeing partially written text (also known as _tearing_).
void serial_buffer()
{
    *MEM_SERIAL = 0xFFFFFF00;
}

/// @details If buffering hasn't been enabled (`serial_buffer()`), this function does
/// nothing.
void serial_flush()
{
    *MEM_SERIAL = 0xFFFFFF01;
}

/// @details If buffering hasn't been enabled (`serial_buffer()`), this function does
/// nothing.
void serial_clear()
{
    *MEM_SERIAL = 0xFFFFFF02;
}

void serial_write_str(const char *s)
{
    while (*s)
    {
        serial_write(*s++);
    }
}

void serial_write_hex(uint32_t n)
{
    for (int i = 28; i >= 0; i -= 4)
    {
        uint32_t m = (n >> i) & 0xF;
        if (m < 10)
        {
            serial_write(m + '0');
        }
        else
        {
            serial_write(m - 10 + 'A');
        }
    }
}

void serial_write_dec(uint32_t n)
{
    if (n > 10)
    {
        serial_write_dec(n / 10);
    }
    serial_write(n % 10 + '0');
}
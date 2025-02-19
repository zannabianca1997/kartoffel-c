#ifndef PANIC_H
#define PANIC_H

#include "lib.h"
#include "serial.h"

// Panic handler equivalent
void panic(const char *info) {
    // If the feature flag for serial panic is enabled, write the panic info to the serial port
    // This would be akin to the Rust feature flag 'serial-panic'
    #ifdef SERIAL_PANIC
    serial_write('\n'); // Add a newline first
    while (*info) {
        serial_write(*info++); // Write each character of the panic message
    }
    #endif

    while (1) {
        // idle
    }
}

#endif // PANIC_H

#ifndef SERIAL_H
#define SERIAL_H

#include "lib.h"

void serial_write(char ch) {
    *MEM_SERIAL = (unsigned int)ch;
}

void serial_buffer() {
    *MEM_SERIAL = 0xFFFFFF00;
}

void serial_flush() {
    *MEM_SERIAL = 0xFFFFFF01;
}

void serial_clear() {
    *MEM_SERIAL = 0xFFFFFF02;
}

void serial_write_str(const char *s) {
    while (*s) {
        serial_write(*s++);
    }
}

void serial_write_char(char c) {
    serial_write(c);
}


void serial_write_hex(uint32_t n) {
    uint32_t m;
    int i;
    for (i = 28; i >= 0; i -= 4) {
        m = (n >> i) & 0xF;
        if (m < 10) {
            serial_write_char(m + '0');
        } else {
            serial_write_char(m - 10 + 'A');
        }
    }
}

#endif // SERIAL_H

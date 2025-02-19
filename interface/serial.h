#ifndef SERIAL_H
#define SERIAL_H

void serial_write(char ch);

void serial_buffer();

void serial_flush();

void serial_clear();

void serial_write_str(const char *s);

void serial_write_char(char c);

void serial_write_hex(uint32_t n);

#endif // SERIAL_H
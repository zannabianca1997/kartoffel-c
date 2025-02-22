/**
 * Serial port interface
 *
 * This file contains functions for writing and managing the serial port.
 */

#ifndef SERIAL_H
#define SERIAL_H

#include "types.h"

/// @brief Writes a single character to the serial port.
///
/// @param ch The character to write.
void serial_write(char ch);

/// @brief Enables buffering.
void serial_buffer();

/// @brief Flushes the buffered characters.
void serial_flush();

/// @brief Clears buffered characters.
void serial_clear();

/// @brief Write a NULL-terminated string to the serial port.
///
/// @param s The string to write.
void serial_write_str(const char *s);

/// @brief Writes the hexadecimal representation of a integer to the serial port.
///
/// @param n The integer to write.
void serial_write_hex(uint32_t n);

/// @brief Writes the decimal representation of a integer to the serial port.
///
/// @param n The integer to write.
void serial_write_dec(uint32_t n);

#endif // SERIAL_H
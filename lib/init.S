# Kartoffel C runtime
#
# Basic runtime that initializes the stack pointer and calls `main()`.

.global _start
.section .init, "ax"

_start:
    la sp, _stack_end
    jal main
    ebreak
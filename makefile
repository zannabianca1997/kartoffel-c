.PHONY: build

all: build

build:
	clang -target riscv32 -march=rv32im -mabi=ilp32 -nostdlib -T kartoffel.ld -o firmware main.c

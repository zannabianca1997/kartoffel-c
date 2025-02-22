# Makefile for Kartoffel

# == Configuration

# Project structure
SRC_DIR?=src
LIB_DIR?=lib

BUILD_DIR?=build

LINKER_SCRIPT?=kartoffel.ld

LIB?=$(BUILD_DIR)/libkartoffel.a
FIRMWARE?=$(BUILD_DIR)/kartoffel.elf

# Compiler setup
CC=clang -target $(TARGET) -c
AS=clang -target $(TARGET) -c
LD=clang -target $(TARGET) 

TARGET?=riscv32
ARCH?=rv32im
ABI?=ilp32

CFLAGS+=-march=$(ARCH) -mabi=$(ABI)                              \
	-I '$(LIB_DIR)'                                              \
	-Wall -Wextra -Wno-unused-parameter                          \
	-Os -fno-stack-protector -ffunction-sections -fdata-sections
ASFLAGS+=
LDFLAGS+=-nostdlib -T '$(LINKER_SCRIPT)' -Wl,--strip-all -Wl,--gc-sections -Wl,--print-gc-sections

# Tools

MKDIR=mkdir -p
RM=rm -fr

AR=ar --target=elf32-little

# == File discovery

LIB_SRCS=$(wildcard $(LIB_DIR)/*.c) 
LIB_ASM=$(wildcard $(LIB_DIR)/*.S)

LIB_OBJS=$(patsubst $(LIB_DIR)/%.c,$(BUILD_DIR)/lib/%.o,$(LIB_SRCS)) $(patsubst $(LIB_DIR)/%.S,$(BUILD_DIR)/lib/%.o,$(LIB_ASM))

SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/src/%.o,$(SRCS))

# == Phony targets

.PHONY: build clean lib firmware
.SUFFIXES:

all: build

build: firmware

lib: $(LIB)
firmware: $(FIRMWARE)

clean:
	$(RM) $(BUILD_DIR)

# == Directories

$(BUILD_DIR)/lib:
	$(MKDIR) $@

$(BUILD_DIR)/src:
	$(MKDIR) $@

# == Library

$(BUILD_DIR)/lib/%.o: $(LIB_DIR)/%.c | $(BUILD_DIR)/lib
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/lib/%.o: $(LIB_DIR)/%.S | $(BUILD_DIR)/lib
	$(AS) $(ASFLAGS) $< -o $@

$(LIB): $(LIB_OBJS)
	$(AR) cr -o $@ $^

# == Firmware

$(BUILD_DIR)/src/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)/src
	$(CC) $(CFLAGS) $< -o $@

$(FIRMWARE): $(OBJS) $(LIB)
	$(LD) $(LDFLAGS) -o $@ $^

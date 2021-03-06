## Creator: Cameron Tacklind
##
## This is the main Makefile for building uC projects. It should only be edited
## to add generic and project specific features. Ideally, there are no real targets
## here. Just variables, or overrides, that the included helper makefiles will use.

# List of C file basenames to build
C =

# List of CPP file basenames to build
CPP = main Board SoftwarePWM TripleBuffer-impl Display

# Select specific LUFA source files to compile like this
#LUFA_SRC = LUFA/Drivers/USB/Class/Common/HIDParser.c

F_CPU = 16000000UL

MCU = atmega32u2

all: build run

run: dfu-erase dfu-flash dfu-reset

uMakerPath = uMaker/

AVRpp_SRC = gccGuard

# Load local settings
-include local.$(shell hostname).mk

# Force setting certain make flags
#include $(uMakerPath)tools/makeflags.mk

# Optional configuration testing for development
include $(uMakerPath)tools/checks.mk

# Defs for our setup
include $(uMakerPath)vars/AVR.mk

# Extra targets
#include $(uMakerPath)tools/nRF51/init-src.mk

# Library targets
#include $(uMakerPath)tools/AVR/lufa.mk
#include $(uMakerPath)tools/nRF51/lib.mk
#include $(uMakerPath)tools/extlib.mk
#include $(uMakerPath)tools/FreeRTOS.mk
include $(uMakerPath)tools/AVR/AVR++.mk

# Build targets
include $(uMakerPath)tools/build.mk

# Programmer targets
include $(uMakerPath)tools/dfu.mk
#include $(uMakerPath)tools/nrfjprog.mk
#include $(uMakerPath)tools/AVR/avrdude.mk

# Directory creation targets
include $(uMakerPath)tools/mkdir.mk

.PHONY: all run

#!/bin/bash
export ARCH=arm
export CROSS_COMPILE=../arm-eabi-4.6/bin/arm-eabi-
# make clean
# make a11ul_defconfig
make all CONFIG_DEBUG_SECTION_MISMATCH=y CONFIG_NO_ERROR_ON_MISMATCH=y

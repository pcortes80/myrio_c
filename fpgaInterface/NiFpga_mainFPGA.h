/*
 * Generated with the FPGA Interface C API Generator 19.0
 * for NI-RIO 19.0 or later.
 */
#ifndef __NiFpga_mainFPGA_h__
#define __NiFpga_mainFPGA_h__

#ifndef NiFpga_Version
   #define NiFpga_Version 190
#endif

#include "NiFpga.h"

/**
 * The filename of the FPGA bitfile.
 *
 * This is a #define to allow for string literal concatenation. For example:
 *
 *    static const char* const Bitfile = "C:\\" NiFpga_mainFPGA_Bitfile;
 */
#define NiFpga_mainFPGA_Bitfile "NiFpga_mainFPGA.lvbitx"

/**
 * The signature of the FPGA bitfile.
 */
static const char* const NiFpga_mainFPGA_Signature = "3AFA09AC018DC8097A6488556538CD55";

#if NiFpga_Cpp
extern "C"
{
#endif

typedef enum
{
   NiFpga_mainFPGA_ControlI32_ledsControl = 0x18000,
} NiFpga_mainFPGA_ControlI32;


#if NiFpga_Cpp
}
#endif

#endif

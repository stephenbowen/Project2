/*
  @file arch_arm32.h
  @brief This file is the header file for arm_arch32.c

  @author Stephen Bowern
  @date Jan 30, 2018
*/

#include <stdio.h>
#include <stdint.h>

#define __SCB_ADDRESS             (0xE000E000)
#define __AIRCR_ADDRESS_OFFSET    (0x00000D0C)
#define __AIRCR                   (0xE000ED0C)
#define __AIRCR_ENDIANNESS_OFFSET (15)
#define __AIRCR_ENDIANNESS_MASK   (0b0000_0000_0000_0000_1000_0000_0000_0000)

/*
  @brief This function returns endianness.

  This function appies a mast to the processors AIRCR register, containing
  a bit representing the endianness of the system.  It then returns the value
  of endianness.

  @return uint32_t
*/
uint32_t ARM32_AIRCR_get_endianness_setting() __attribute__((always_inline));

/*
  @file arch_arm32.c  
  @brief This file is used to determine the endianness setting of an
  architecture.

  The file consists of one fucntion.  The fuction returns the endianness of the
  architecture on which it is being run.

  @author Stephen Bowern
  @date Feb 2, 2018
*/

#include <stdio.h>
#include <stdint.h>
#include <arch_arm32.h>

/*
  @brief This function returns endianness.

  This function appies a mast to the processors AIRCR register, containing
  a bit representing the endianness of the system.  It then returns the value
  of endianness.

  @return uint32_t
*/
__attribute__((always_inline)) uint32_t ARM32_AIRCR_get_endianness_setting()
{
  return ((__AIRCR_ENDIANNESS_MASK) >> __AIRCR_ENDIANNESS_OFFSET);
}

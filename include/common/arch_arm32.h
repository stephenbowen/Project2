/*
  @file arch_arm32.h
  @brief This file is the header file for arm_arch32.c

  @author Stephen Bowern
  @date Jan 30, 2018
*/

#include <stdio.h>
#include <stdint.h>

#define __SCB_ADDRESS                      (0xE000E000)

#define __AIRCR_ADDRESS_OFFSET             (0x00000D0C)
#define __AIRCR                            (0xE000ED0C)
#define __AIRCR_ENDIANNESS_OFFSET          (15)
#define __AIRCR_ENDIANNESS_MASK            (0b00000000000000001000000000000000)

#define __CPUID_ADDRESS_OFFSET             (0x00000D00)
#define __CPUID                            (0xE000ED00)
#define __CPUID_PART_NO_OFFSET             (4)
#define __CPUID_PART_NO_MASK               (0b00000000000000001111111111110000)

#define __CCR_ADDRESS_OFFSET               (0x00000D14)
#define __CCR                              (0xE000ED14)
#define __CCR_STK_ALIGNMENT_OFFSET         (9)
#define __CCR_STK_ALIGNMENT_MASK           (0b00000000000000000000001000000000)
#define __CCR_UNALIGNED_ACCESS_TRAP_OFFSET (3)
#define __CCR_UNALIGNED_ACCESS_TRAP_MASK   (0b00000000000000000000000000001000)
#define __CCR_DIVIDE_BY_ZERO_TRAP_OFFSET   (4)
#define __CCR_DIVIDE_BY_ZERO_TRAP_MASK     (0b00000000000000000000000000010000)

/*
 * @brief This function returns endianness.
 *
 * This function appies a mask to the processors AIRCR register, containing
 * a bit representing the endianness of the system.  It then returns the value
 * of endianness.
 *
 * @param  none
 * @return uint32_t
 */
__attribute__((always_inline)) inline uint32_t ARM32_AIRCR_get_endianness_setting();

/*
 * @brief This function returns stack alignment.
 *
 * This function reads the stack alignment in the CCR regiester, and reuturns
 * the alignment value.
 *
 * @param  none
 * @return uint32_t
 */
__attribute__((always_inline)) inline uint32_t ARM32_CCR_get_stack_alignment();

/*
 * @brief This function returns the CPU part number.
 *
 * This function reads the part nubmer bits in the CPUID regiester, and reuturns
 * the part number value.
 *
 * @param  none
 * @return uint32_t
 */
__attribute__((always_inline)) inline uint32_t ARM32_CPUID_get_part_number();

/*
 * @brief This function enables the divide by zero trap.
 *
 * This function enables the divide by zero trap in the CCR register by setting
 * the applicable bit.
 *
 * @param  none
 * @return void
 */
__attribute__((always_inline)) inline void ARM32_CCR_enable_divide_by_zero_trap();

/*
 * @brief This function enables the unaligned access trap.
 *
 * This function enables the unaligned access tram in the CCR register by
 * setting the applicable bit.
 *
 * @param  none
 * @return void
 */
__attribute__((always_inline)) inline void ARM32_CCR_enable_unaligned_access_trap();

/*
 * @brief This function generates an unaligned access trap.
 *
 * This function generates an unaligned access trap by performing an unaligned
 * access after the trap has been enabled.
 *
 * @param  none
 * @return void
 */
__attribute__((always_inline)) inline void ARM32_create_unaligned_access_trap();

/*
 * @brief This function generates a divide by zero trap
 *
 * This function generates a divide by zero trap by performing a divide by zero
 * function after the trap has been enabled.
 *
 * @param  none
 * @return void
 */
__attribute__((always_inline)) inline void ARM32_create_divide_by_zero_trap();

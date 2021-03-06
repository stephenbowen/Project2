/*
 * @file arch_arm32.c  
 * @brief This file is used to determine the endianness setting of an
 * architecture.
 *
 * The file consists of one fucntion.  The fuction returns the endianness of the
 * architecture on which it is being run.
 *
 * @author Stephen Bowern
 * @date Feb 25, 2018
 */

#include <stdio.h>
#include <stdint.h>
#include "arch_arm32.h"

/*
 * @brief This function returns endianness.
 *
 * This function appies a mast to the processors AIRCR register, containing
 * a bit representing the endianness of the system.  It then returns the value
 * of endianness.
 *
 * @return uint32_t
 */
uint32_t ARM32_AIRCR_get_endianness_setting()
{
	volatile uint32_t *ptr;
	ptr = (uint32_t *)__AIRCR;

  return ((__AIRCR_ENDIANNESS_MASK) >> __AIRCR_ENDIANNESS_OFFSET);
}

/*
 * @brief This function returns stack alignment.
 *
 * This function reads the stack alignment in the CCR regiester, and reuturns
 * the alignment value.
 *
 * @param  none
 * @return uint32_t
 */
uint32_t ARM32_CCR_get_stack_alignment()
{
	volatile uint32_t *ptr;
	ptr = (uint32_t *)__CCR;

	return ((*ptr & __CCR_STK_ALIGNMENT_MASK) >> __CCR_STK_ALIGNMENT_OFFSET);
}

/*
 * @brief This function returns the CPU part number.
 *
 * This function reads the part nubmer bits in the CPUID regiester, and reuturns
 * the part number value.
 *
 * @param  none
 * @return uint32_t
 */
uint32_t ARM32_CPUID_get_part_number()
{
	volatile uint32_t *ptr;
	ptr = (uint32_t *)__CPUID;

	return ((*ptr & __CPUID_PART_NO_MASK) >> __CPUID_PART_NO_OFFSET);
}

/*
 * @brief This function enables the divide by zero trap.
 *
 * This function enables the divide by zero trap in the CCR register by setting
 * the applicable bit.
 *
 * @param  none
 * @return void
 */
void ARM32_CCR_enable_divide_by_zero_trap()
{
	volatile uint32_t *ptr;
	ptr = (uint32_t *)__CCR;

	*ptr |= (1 << __CCR_DIVIDE_BY_ZERO_TRAP_OFFSET);
}

/*
 * @brief This function enables the unaligned access trap.
 *
 * This function enables the unaligned access tram in the CCR register by
 * setting the applicable bit.
 *
 * @param  none
 * @return void
 */
void ARM32_CCR_enable_unaligned_access_trap()
{
	volatile uint32_t *ptr;
	ptr = (uint32_t *)__CCR;

	*ptr |= (1 << __CCR_UNALIGNED_ACCESS_TRAP_OFFSET);
}

/*
 * @brief This function generates an unaligned access trap.
 *
 * This function generates an unaligned access trap by performing an unaligned
 * access after the trap has been enabled.
 *
 * @param  none
 * @return void
 */
void ARM32_create_unaligned_access_trap()
{
	uint8_t var;
	uint32_t *ptr = (uint32_t *)(&var);

	return;
}

/*
 * @brief This function generates a divide by zero trap
 *
 * This function generates a divide by zero trap by performing a divide by zero
 * function after the trap has been enabled.
 *
 * @param  none
 * @return void
 */
void ARM32_create_divide_by_zero_trap()
{
	uint8_t num = (1 / 0);

	return;
}

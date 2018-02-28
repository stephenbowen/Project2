/*
 * @file unittest.h 
 * @brief This file is the header file for unittest.c.
 *
 * @author Stephen Bowern
 * @date Feb 25, 2018
 */

#include <stdio.h>
#include <stdint.h>
#include "MKL25Z4.h"

#define WORD_SIZE_8   (8)
#define ARRAY_SIZE_32 (32)
#define LENGTH_16     (16)
#define LENGTH_10     (10)
#define LENGTH_8      (8)
#define VALUE_FF      (0XFF)
#define BASE_10       (10)
#define BASE_16       (16)

/*
 * @brief This function tests the my_memmove function.
 *
 * @param none
 * @return void
 */
void memmove_test();

/*
 * @brief This function tests the my_memset function.
 *
 * @param none
 * @return void
 */
void memset_test();

/*
 * @brief This function tests the my_memzero function.
 *
 * @param none
 * @return void
 */
void memzero_test();

/*
 * @brief This function tests the my_reverse function.
 *
 * @param none
 * @return void
 */
void reverse_test();

/*
 * @brief This function tests the my_atoi function.
 *
 * @param none
 * @return void
 */
void conversion_test();

/*
 * @brief This function tests the swap_data_endianness function.
 *
 * @param none
 * @return void
 */
void endian_test();

/*
 * @brief This function tests the circular buffer functions.
 *
 * @param none
 * @return void
 */
void buf_test();

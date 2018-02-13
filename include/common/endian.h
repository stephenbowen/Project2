/*
  @file endian.h
  @brief This file is the header file for endian.c

  @author Stephen Bowern
  @date Feb 1, 2018
*/

#include <stdio.h>

#define SWAP_ERROR -1
#define SWAP_NO_ERROR 0
#define LITTLE_ENDIAN 0
#define BIG_ENDIAN 1

/*
  @brief This function swaps the endianness of a length of 8 bit integers.

  This function takes in an 8 bit ineger pointer, and a size_t lenth,
  representing the number of words to swap.  The fucntion temporarily stores
  the data in an array and then writes back the data in reverse order to the
  pointer.  The function returns error or no error.

  @return int32_t
*/
int32_t swap_data_endianness(uint8_t *, size_t);

/*
  @brief This function determines endianness of a value.

  This function takes in no argurments.  The function outputs the endianness of
  the architecture that the execuatble is running on.  It does this by assigning
  a pointer to a multi-byte vairable.  If the pointer points at the MSB,
  BIG_ENDIAN is returned.  Otherwise, LITTLE_ENDIAN is returned.

  @return uint32_t
*/
uint32_t determine_indianness();

/*
  @file endian.c  
  @brief This file is used to dispaly and swap endianness.

  The file consists of two functions: swap_data_endianness() and
  determine_endianness.  The swap function reverses the order of bytes in a
  given word.  The determine function reads a word and returns the endianness
  value.

  @author Stephen Bowern
  @date Feb 1, 2018
*/

#include <stdio.h>
#include <stdint.h>
#include <endian.h>

/*
  @brief This function swaps the endianness of a length of 8 bit integers.

  This function takes in an 8 bit ineger pointer, and a size_t lenth,
  representing the number of words to swap.  The fucntion temporarily stores
  the data in an array and then writes back the data in reverse order to the
  pointer.  The function returns error or no error.

  @return int32_t
*/
int32_t swap_data_endianness(uint32_t *data, size_t type_length)
{
	/*check for valid pointer*/
  if(data == 0)
    return SWAP_ERROR;

	/*swap endianness with bit manipulation based on size 8, 16, or 32 bit*/
	if(type_length == 1)                      /*8 bit*/
		;
	else if(type_length == 2)                 /*16 bit*/
		*data = (((*data & 0x00FF) << 8) |
             ((*data & 0xFF00) >> 8));

	else if(type_length == 4)                 /*32 bit*/
		*data = (((*data & 0x000000FF) << 24) |
             ((*data & 0x0000FF00) <<  8) |
             ((*data & 0x00FF0000) >>  8) |
             ((*data & 0xFF000000) >> 24));
	else                                      /*invalid size entered*/
		return SWAP_ERROR;
  
  return SWAP_NO_ERROR;
}

/*
  @brief This function determines endianness of a value.

  This function takes in no argurments.  The function outputs the endianness of
  the architecture that the execuatble is running on.  It does this by assigning
  a pointer to a multi-byte vairable.  If the pointer points at the MSB,
  BIG_ENDIAN is returned.  Otherwise, LITTLE_ENDIAN is returned.

  @return uint32_t
*/
uint32_t determine_endianness()
{
  uint16_t temp = 0x0F;
  uint8_t *ptr = (uint8_t *) &temp;

  if(*ptr == 0)
    return BIG_ENDIAN;
  else
    return LITTLE_ENDIAN;
}

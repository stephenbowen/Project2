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
int32_t swap_data_endianness(uint8_t *data, size_t type_length)
{
  uint8_t temp[type_length];    /*temporary storage for data bytes*/
  uint8_t *ptr = temp;
  uint8_t *origin;              /*set the origin address for later retreival*/
  origin = data;

  if(data == 0)
    return SWAP_ERROR;
  
  /*copy bytes from data to temp*/
  for(int x = 1 ; x < type_length ; x++)
  {
    *ptr = *data;
    ptr++;
    data++;
  }
  data = origin;                /*reset data pointer back to its origin*/

  /*copy bytes from temp back to data in reverse order*/
  for(int x = type_length ; x > 0 ; x--)
  {
    *data = *ptr;
    data++;
    ptr--;
  }
  data = origin;

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

/*
  @file conversion.c  
  @brief This file is the header file for conversion.c

  @author Stephen Bowern
  @date Jan 30, 2018
*/

#include <stdio.h>
#include <stdint.h>

#define ERROR 1

/*
  @brief This function converts an integer value to an ASCII value

  This function takes in a 32 bit data intiger, an integer pointer, and a base.
  The function converts the integer data to ASCII with respect to the base, and 
  assigns that ASCII string to the pointer.  The function returns an integer
  representing the number of the ASCII characters assigned, including negative
  sign and null terminator.

  @return uint8_t
*/
uint8_t my_itoa(int32_t, uint8_t *, uint32_t);

/*
  @brief This function converts an ASCII value to an integer value

  This function takes in an integer pointer (pointing to the ASCII data), an
  integer representing the number of digits being input, and a base.
  The function converts the ASCII data to an integer with respect to the base,
  and then returns that value as a 32 bit signed integer.

  @return uint32_t
*/
int32_t my_atoi(uint8_t *, uint8_t , uint32_t);


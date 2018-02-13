/*
  @file debug.c
  @brief This file is used to convert an integer to hex

  The file consists of one function that outputs the hex value of an unsigned
  8 bit integer.

  @author Stephen Bowern
  @date Jan 30, 2018
*/

#include <stdio.h>
#include <stdint.h>
#include <debug.h>

/*
  @brief This function converts an integer value hex

  This function takes in a pointer to an unsigned 8 bit integer array and a 32
  bit integer representing the length of the array.  The function converts the
  array to hex and displays the hex value.

  @return void
*/
void print_array(uint8_t *start, uint32_t length)
{
  uint8_t *ptr = start;

  /*check for invalid pointer*/
  if(start == NULL)
    return;

  for(uint8_t x = 0 ; x < length ; x++)
  {
    printf("%X ", *ptr);
    ptr++;
  }

  printf("\n");

  return;
}

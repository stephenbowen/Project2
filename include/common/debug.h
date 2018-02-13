/*
  @file debug.h
  @brief This file is the header file for debug.c

  @author Stephen Bowern
  @date Jan 30, 2018
*/

#include <stdio.h>
#include <stdint.h>

/*
  @brief This function converts an integer value hex

  This function takes in a pointer to an unsigned 8 bit integer array and a 32
  bit integer representing the length of the array.  The function converts the
  array to hex and displays the hex value.

  @return void
*/
void print_array(uint8_t *, uint32_t);

/*
  @file memory. 
  @brief This file is the header file for memory.c

  @author Stephen Bowern
  @date Jan 25, 2018
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define ERROR 1

/*
  @brief This function copies data to a specified address.

  This function takes in a pointer to a source of data, a pointer to a data
  destination, and the length of the data.  The function copies the data into
  a temporary array and then writes that data to the desination address.  The
  function then returns the address of the destination.

  @return uint8_t *
*/
uint8_t *my_memmove(uint8_t *, uint8_t *, size_t);

/*
  @brief This function copies data to a specified address.

  This function takes in a pointer to a source of data, a pointer to a data
  destination, and the length of the data.  The function copies the data to the
  destination address one byte at a time, regardless of memory overlap.  The
  function then returns the address of the destination.

  @return uint8_t *
*/
uint8_t *my_memcpy(uint8_t *, uint8_t *, size_t);

/*
  @brief This function sets number of data values to a given value.

  This function takes in a pointer to a source of data, a number of data values
  and the value to be written.  The function writes the given data value to each
  of the address for the given length.  The function then returns the address
  of the source of data.

  @return uint8_t *
*/
uint8_t *my_memset(uint8_t *, size_t, uint8_t);

/*
  @brief This function set the data value to 0 for a number of addresses.

  This function takes in a pointer to a source of data, and the length of the
  data to be written to.  The function writes 0 to each of these data
  addresses.  The functio then returns the address of the source of data.

  @return uint8_t *
*/
uint8_t *my_memzero(uint8_t *, size_t);

/*
  @brief This function reverses a set of data bytes.

  This function takes in a pointer to a source of data, and the length of data.
  The funciton copies the data to a temporary array, then writes the array's
  data back to the source in reverse order.  The function then returns the
  address of the source.

  @return uint8_t *
*/
uint8_t *my_reverse(uint8_t *, size_t);

/*
  @brief This function dynamically allocates memory.

  This function takes in a length of data.  I then dynamically allocates memory
  of that length.  The function returns the address of the allocated memory.

  @return int32_t
*/
int32_t *reserve_words(size_t);

/*
  @brief This function frees previously allocated memory.

  This function takes in a pointer to a memory location.  It then frees the
  the memory that was previosly dynamically allocated.  The function returns
  nothing.

  @return void
*/
uint8_t free_words(uint32_t *);

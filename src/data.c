/*
  @file data.c  
  @brief This file is used to display data type sizes

  The file consists of three functions.  Each funtion displays the data type
  size (in number of bytes) of a number of types.

  @author Stephen Bowern
  @date Feb 1, 2018
*/

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include "data.h"
#include "platform.h"

/*
  @brief Fucntion to display data type sizes

  This function does not take in any values or return any value.
  The function prints the size of each of the C standard types.

  @return void
*/
void print_cstd_type_sizes()
{
  size_t temp = 1;
  temp *= 1;        /*opearation to prevent compile error when print
                      statement not used for KL25Z*/
  #if defined(__GNUC__)
  #pragma GCC diagnostic ignored "-Wunused-but-set-variable"

  temp = sizeof(char);
  PRINTF("size of char = %d\n", temp);

  temp = sizeof(short);
  PRINTF("size of short = %d\n", temp);

  temp = sizeof(int);
  PRINTF("size of int = %d\n", temp);

  temp = sizeof(long);
  PRINTF("size of long = %d\n", temp);

  temp = sizeof(double);
  PRINTF("size of double = %d\n", temp);

  temp = sizeof(float);
  PRINTF("size of float = %d\n", temp);

  temp = sizeof(unsigned char);
  PRINTF("size of unsigned char = %d\n", temp);

  temp = sizeof(unsigned int);
  PRINTF("size of unsigned int = %d\n", temp);

  temp = sizeof(unsigned long);
  PRINTF("size of unsigned long = %d\n", temp);

  temp = sizeof(signed char);
  PRINTF("size of signed char = %d\n", temp);

  temp = sizeof(signed int);
  PRINTF("size of signed int = %d\n", temp);

  temp = sizeof(signed long);
  PRINTF("size of signed long = %d\n", temp);

  #endif
}

/*
  @brief Fucntion to display data type sizes

  This function does not take in any values or return any value.
  The function prints the size of each of the standard integer types.

  @return void
*/
void print_stdint_type_sizes()
{
  size_t temp = 1;
  temp *= 1;        /*opearation to prevent compile error when print
                      statement not used for KL25Z*/
  #if defined(__GNUC__)
  #pragma GCC diagnostic ignored "-Wunused-but-set-variable"

  temp = sizeof(int8_t);
  PRINTF("size of int8_t = %d\n", temp);

  temp = sizeof(uint8_t);
  PRINTF("size of uint8_t = %d\n", temp);

  temp = sizeof(int16_t);
  PRINTF("size of int16_t = %d\n", temp);

  temp = sizeof(uint16_t);
  PRINTF("size of uint16_t = %d\n", temp);

  temp = sizeof(int32_t);
  PRINTF("size of int32_t = %d\n", temp);

  temp = sizeof(uint32_t);
  PRINTF("size of uint32_t = %d\n", temp);

  temp = sizeof(uint_fast8_t);
  PRINTF("size of uint_fast8_t = %d\n", temp);

  temp = sizeof(uint_fast16_t);
  PRINTF("size of uint_fast16_t = %d\n", temp);

  temp = sizeof(uint_fast32_t);
  PRINTF("size of uint_fast32_t = %d\n", temp);

  temp = sizeof(uint_least8_t);
  PRINTF("size of uint_least8_t = %d\n", temp);

  temp = sizeof(uint_least16_t);
  PRINTF("size of uint_least16_t = %d\n", temp);

  temp = sizeof(uint_least32_t);
  PRINTF("size of uint_least32_t = %d\n", temp);

  temp = sizeof(size_t);
  PRINTF("size of size_t = %d\n", temp);

  temp = sizeof(ptrdiff_t);
  PRINTF("size of ptrdiff_t = %d\n", temp);

  #endif
}

/*
  @brief Fucntion to display data type sizes

  This function does not take in any values or return any value.
  The function prints the size of each of the pointer types.

  @return void
*/
void print_pointer_sizes()
{
  size_t temp =1;
  temp *= 1;        /*opearation to prevent compile error when print
                      statement not used for KL25Z*/
  #if defined(__GNUC__)
  #pragma GCC diagnostic ignored "-Wunused-but-set-variable"

  temp = sizeof(char *);
  PRINTF("size of char * = %d\n", temp);

  temp = sizeof(short *);
  PRINTF("size of short * = %d\n", temp);

  temp = sizeof(int *);
  PRINTF("size of int * = %d\n", temp);

  temp = sizeof(long *);
  PRINTF("size of long * = %d\n", temp);

  temp = sizeof(double *);
  PRINTF("size of double * = %d\n", temp);

  temp = sizeof(float *);
  PRINTF("size of float * = %d\n", temp);

  temp = sizeof(void *);
  PRINTF("size of void * = %d\n", temp);

  temp = sizeof(int8_t *);
  PRINTF("size of int8_t * = %d\n", temp);

  temp = sizeof(int16_t *);
  PRINTF("size of int16_t * = %d\n", temp);

  temp = sizeof(int32_t *);
  PRINTF("size of int32_t * = %d\n", temp);

  temp = sizeof(char **);
  PRINTF("size of char ** = %d\n", temp);

  temp = sizeof(int **);
  PRINTF("size of int ** = %d\n", temp);

  temp = sizeof(void **);
  PRINTF("size of void ** = %d\n", temp);

  temp = sizeof(ptrdiff_t);
  PRINTF("size of ptrdiff_t = %d\n", temp);

  #endif
}

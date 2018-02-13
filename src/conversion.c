/*
  @file conversion.c  
  @brief This file is used to convert integers to ASCII and vice versa

  The file consists of two functions: itoa() and atoi().  itoa() takes in an 
  integer value and outputs the ASCII equivalent of that value.  atoi() takes
  in an ASCII value and converts it to an integer.

  @author Stephen Bowern
  @date Jan 30, 2018
*/

#include <stdio.h>
#include <stdint.h>
#include <conversion.h>

/*
  @brief This function converts an integer value to an ASCII value

  This function takes in a 32 bit data intiger, an integer pointer, and a base.
  The function converts the integer data to ASCII with respect to the base, and 
  assigns that ASCII string to the pointer.  The function returns an integer
  representing the number of the ASCII characters assigned, including negative
  sign and null terminator.

  @return uint8_t
*/
uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base)
{

   uint8_t total = 0;        /*counts the total number of ASCII values*/
   uint8_t isneg = 0;        /*tracks the sign of the integer*/
   uint8_t *origin;
   origin = ptr;

  /*check for invalid pointer*/
  if(ptr == NULL)
    return ERROR;

  /*check for invalid base*/
  if(base < 2 || base > 16)
    return ERROR;

  /*check if the integer is negative*/
  if(data < 0)
  {
    isneg = 1;          /*integer is recognizes as negative*/
    data *= -1;         /*turns data value to positive*/
  }

  /*assign null character, and increment pointer*/
  *ptr = '\0';
  ptr++;
  total++;

  /*while the data is greater than 0, assign the modulus
    to the character array, and trucate the LSB of data
  */  
  while(data != 0)
  { 
    uint32_t remainder = data % base;

    if(remainder > 9)
      remainder += ('A' - 10);
    else
      remainder += '0';

    *ptr = remainder;      /*assign ASCII character*/
    ptr++;                 /*increment ASCII pointer*/
    total++;               /*increment number of ASCII characters*/
    data /= base;          /*right shift integer value for next operation*/
  }

  if(isneg)
  {
    *ptr = '-';            /*assign '-' to last character if negative*/
    total++;
  }

  ptr = origin;            /*return pointer to its starting point*/

  /*reverse the character array*/
  uint8_t first = 0;
  uint8_t last = total - 1;
  uint8_t temp;

  while(first < last)
  {
    temp = *(ptr + last);
    *(ptr + last) = *(ptr + first);
    *(ptr + first) = temp;

    first++;
    last--;
  }

  return total;
}

/*
  @brief This function converts an ASCII value to an integer value

  This function takes in an integer pointer (pointing to the ASCII data), an
  integer representing the number of digits being input, and a base.
  The function converts the ASCII data to an integer with respect to the base,
  and then returns that value as a 32 bit signed integer.

  @return uint32_t
*/
int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base)
{
  int8_t isneg = 1;          /*1 if the input value is negative, -1 otherwise*/
  int32_t result = 0;

  /*check for invalid pointer*/
  if(ptr == NULL)
    return ERROR;

  /*check for invalid base*/
  if(base < 2 || base > 16)
    return ERROR;

  /*check if the number is negative*/
  if(*ptr == '-')
  {
    isneg = -1;    
    ptr++;
  }

  for(uint8_t x = 0 ; *ptr != '\0' ; x++)
  {
      result = result * base + *ptr - '0';

    ptr++;
  }

  return (result * isneg);
}

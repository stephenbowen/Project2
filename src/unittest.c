/*
 * @file unittest.c
 * @brief This file tests various functions for project 2.
 *
 * @author Stephen Bowern
 * @date Feb 26, 2018
 */

#include <stdio.h>
#include <stdint.h>
#include "unittest.h"
#include "MKL25Z4.h"
#include "memory.c"
#include "conversion.c"
#include "endian.c"
#include "circbuf.c"
#include "debug.c"

int main()
{
	//memmove_test();
	//memset_test();
	//memzero_test();
	//reverse_test();
	//conversion_test();
	//endian_test();
	buf_test();
	return 0;
}

/*
 * @brief This function tests the my_memmove function.
 *
 * @param none
 * @return void
 */
void memmove_test()
{
	uint8_t *data;     /*data array pointer*/
	uint8_t *ptr1;     /*1st pointer*/
	uint8_t *ptr2;     /*2nd pointer*/
	uint8_t fail = 0;  /*fail condition*/

	/*start of NO OVERLAP test*/
	printf("MEMMOVE TEST\n  a) no overlap test\n");

	/*allocate memory to data*/
	data = (uint8_t *) reserve_words(WORD_SIZE_8);

	/*check for valid pointer*/
	if(data == NULL)
		printf("Fail: Null Pointer\n");
	else
		printf("Pass: Valid Pointer\n");

	/*initialize the array with ascending values*/
	for(uint8_t n = 0 ; n < ARRAY_SIZE_32 ; n++)
		data[n] = n;

	/*set pointers to the start and middle positions*/
	ptr1 = &data[0];
	ptr2 = &data[LENGTH_16];

	/*print array before move*/
  print_array(data, ARRAY_SIZE_32);

	/*call memmove function*/
	my_memmove(ptr1, ptr2, LENGTH_16);

	/*print array after move*/
  print_array(data, ARRAY_SIZE_32);

	/*test for correct memmove operation*/
	for(uint8_t n = 0 ; n < LENGTH_16 ; n++)
	{
		if(data[n] != data[n + LENGTH_16])
			fail = 1;
	}
		/*display test results, reset fail flag*/
		if(fail == 0)
			printf("Pass: Successful Memmove\n\n");
		else
			printf("Fail: Unsuccessful Memmove\n\n");
		fail = 0;

	/*free allocated memory*/
	free_words((uint32_t *) data);

	/*reset pointers*/
	data = NULL;
	ptr1 = NULL;
	ptr2 = NULL;
/******************************************************************************/
	/*start of SRC IN DST test*/
	printf("  b) src in dst test\n");

	/*allocate memory to data*/
	data = (uint8_t *) reserve_words(WORD_SIZE_8);

	/*check for valid pointer*/
	if(data == NULL)
		printf("Fail: Null Pointer\n");
	else
		printf("Pass: Valid Pointer\n");

	/*initialize the array with ascending values*/
	for(uint8_t n = 0 ; n < ARRAY_SIZE_32 ; n++)
		data[n] = n;

	/*set pointers to posiitons such that dst is in the src region*/
	ptr1 = &data[LENGTH_8];
	ptr2 = &data[0];

	/*print array before move*/
  print_array(data, ARRAY_SIZE_32);

	/*call memmove function*/
	my_memmove(ptr1, ptr2, LENGTH_16);

	/*print array after move*/
  print_array(data, ARRAY_SIZE_32);

	/*test for correct memmove operation*/
	for(uint8_t n = 0 ; n < LENGTH_8 ; n++)
	{
		if(data[n] != (LENGTH_8 +n))
			fail = 1;
	}
		/*display test results, reset fail flag*/
		if(fail == 0)
			printf("Pass: Successful Memmove with Overlap\n\n");
		else
			printf("Fail: Unsuccessful Memmove with Overlap\n\n");
		fail = 0;

	/*free allocated memory*/
	free_words((uint32_t *) data);

	/*reset pointers*/
	data = NULL;
	ptr1 = NULL;
	ptr2 = NULL;
/******************************************************************************/
	/*start of DST IN SRC test*/
	printf("  c) dst in src test\n");

	/*allocate memory to data*/
	data = (uint8_t *) reserve_words(WORD_SIZE_8);

	/*check for valid pointer*/
	if(data == NULL)
		printf("Fail: Null Pointer\n");
	else
		printf("Pass: Valid Pointer\n");

	/*initialize the array with ascending values*/
	for(uint8_t n = 0 ; n < ARRAY_SIZE_32 ; n++)
		data[n] = n;

	/*set pointers to posiitons such that dst is in the src region*/
	ptr1 = &data[0];
	ptr2 = &data[LENGTH_8];

	/*print array before move*/
  print_array(data, ARRAY_SIZE_32);

	/*call memmove function*/
	my_memmove(ptr1, ptr2, LENGTH_16);

	/*print array after move*/
  print_array(data, ARRAY_SIZE_32);

	/*test for correct memmove operation*/
	for(uint8_t n = 0 ; n < LENGTH_8 ; n++)
	{
		if(data[n] != data[n + LENGTH_8])
			fail = 1;
	}
		/*display test results, reset fail flag*/
		if(fail == 0)
			printf("Pass: Successful Memmove with Overlap\n\n");
		else
			printf("Fail: Unsuccessful Memmove with Overlap\n\n");
		fail = 0;

	/*free allocated memory*/
	free_words((uint32_t *) data);

	/*reset pointers*/
	data = NULL;
	ptr1 = NULL;
	ptr2 = NULL;
/******************************************************************************/
	/*start of SRC == DST test*/
	printf("  d) dst == src test\n");

	/*allocate memory to data*/
	data = (uint8_t *) reserve_words(WORD_SIZE_8);

	/*check for valid pointer*/
	if(data == NULL)
		printf("Fail: Null Pointer\n");
	else
		printf("Pass: Valid Pointer\n");

	/*initialize the array with ascending values*/
	for(uint8_t n = 0 ; n < ARRAY_SIZE_32 ; n++)
		data[n] = n;

	/*set pointers to posiitons such that dst is in the src region*/
	ptr1 = &data[0];
	ptr2 = &data[0];

	/*print array before move*/
  print_array(data, ARRAY_SIZE_32);

	/*call memmove function*/
	my_memmove(ptr1, ptr2, LENGTH_16);

	/*print array after move*/
  print_array(data, ARRAY_SIZE_32);

	/*test for correct memmove operation*/
	for(uint8_t n = 0 ; n < ARRAY_SIZE_32 ; n++)
	{
		if(data[n] != n)
			fail = 1;
	}
		/*display test results, reset fail flag*/
		if(fail == 0)
			printf("Pass: Successful Memmove\n\n");
		else
			printf("Fail: Unsuccessful Memmove\n\n");
		fail = 0;

	/*free allocated memory*/
	free_words((uint32_t *) data);

	/*reset pointers*/
	data = NULL;
	ptr1 = NULL;
	ptr2 = NULL;

	return;
}

/*
 * @brief This function tests the my_memset function.
 *
 * @param none
 * @return void
 */
void memset_test()
{
	uint8_t *data;     /*data array pointer*/
	uint8_t *ptr1;     /*1st pointer*/
	uint8_t fail = 0;  /*fail condition*/

	printf("MEMSET TEST\n");

	/*allocate memory to data*/
	data = (uint8_t *) reserve_words(WORD_SIZE_8);

	/*check for valid pointer*/
	if(data == NULL)
		printf("Fail: Null Pointer\n");
	else
		printf("Pass: Valid Pointer\n");

	/*initialize the array with ascending values*/
	for(uint8_t n = 0 ; n < ARRAY_SIZE_32 ; n++)
		data[n] = n;

	/*set pointer to the start position*/
	ptr1 = &data[0];

	/*print array before move*/
  print_array(data, ARRAY_SIZE_32);

	/*call memset function*/
	my_memset(ptr1, ARRAY_SIZE_32, VALUE_FF);

	/*print array after move*/
  print_array(data, ARRAY_SIZE_32);

	/*test for correct memmove operation*/
	for(uint8_t n = 0 ; n < ARRAY_SIZE_32 ; n++)
	{
		if(data[n] != VALUE_FF)
			fail = 1;
	}
		/*display test results, reset fail flag*/
		if(fail == 0)
			printf("Pass: Successful Memset\n\n");
		else
			printf("Fail: Unsuccessful Memset\n\n");
		fail = 0;

	/*free allocated memory*/
	free_words((uint32_t *) data);

	/*reset pointers*/
	data = NULL;
	ptr1 = NULL;

	return;
}

/*
 * @brief This function tests the my_memzero function.
 *
 * @param none
 * @return void
 */
void memzero_test()
{
	uint8_t *data;     /*data array pointer*/
	uint8_t *ptr1;     /*1st pointer*/
	uint8_t fail = 0;  /*fail condition*/

	printf("MEMZERO TEST\n");

	/*allocate memory to data*/
	data = (uint8_t *) reserve_words(WORD_SIZE_8);

	/*check for valid pointer*/
	if(data == NULL)
		printf("Fail: Null Pointer\n");
	else
		printf("Pass: Valid Pointer\n");

	/*initialize the array with ascending values*/
	for(uint8_t n = 0 ; n < ARRAY_SIZE_32 ; n++)
		data[n] = n;

	/*set pointer to the start position*/
	ptr1 = &data[0];

	/*print array before move*/
  print_array(data, ARRAY_SIZE_32);

	/*call memset function*/
	my_memzero(ptr1, ARRAY_SIZE_32);

	/*print array after move*/
  print_array(data, ARRAY_SIZE_32);

	/*test for correct memmove operation*/
	for(uint8_t n = 0 ; n < ARRAY_SIZE_32 ; n++)
	{
		if(data[n] != 0)
			fail = 1;
	}
		/*display test results, reset fail flag*/
		if(fail == 0)
			printf("Pass: Successful Memzero\n\n");
		else
			printf("Fail: Unsuccessful Memzero\n\n");
		fail = 0;

	/*free allocated memory*/
	free_words((uint32_t *) data);

	/*reset pointers*/
	data = NULL;
	ptr1 = NULL;

	return;
}

/*
 * @brief This function tests the my_reverse function.
 *
 * @param none
 * @return void
 */
void reverse_test()
{
	uint8_t *data;     /*data array pointer*/
	uint8_t *copy;     /*1st pointer*/
	uint8_t fail = 0;  /*fail condition*/

	printf("REVERSE TEST\n");

	/*allocate memory to data*/
	data = (uint8_t *) reserve_words(WORD_SIZE_8);
	copy = (uint8_t *) reserve_words(WORD_SIZE_8);

	/*check for valid pointer*/
	if(data == NULL)
		printf("Fail: Null Pointer\n");
	else
		printf("Pass: Valid Pointer\n");

	/*initialize the array with ascending values*/
	for(uint8_t n = 0 ; n < ARRAY_SIZE_32 ; n++)
	{
		data[n] = n;
		copy[n] = n;
	}

	/*print array before move*/
  print_array(data, ARRAY_SIZE_32);

	/*call reverse function*/
	my_reverse(data, ARRAY_SIZE_32);

	/*print array after move*/
  print_array(data, ARRAY_SIZE_32);

	/*test for correct memmove operation*/
	for(uint8_t n = 0 ; n < ARRAY_SIZE_32 ; n++)
	{
		if(data[n] != copy[ARRAY_SIZE_32 - n -1])
			fail = 1;
	}
		/*display test results, reset fail flag*/
		if(fail == 0)
			printf("Pass: Successful Reverse\n\n");
		else
			printf("Fail: Unsuccessful Reverse\n\n");
		fail = 0;

	/*free allocated memory*/
	free_words((uint32_t *) data);

	/*reset pointers*/
	data = NULL;
	copy = NULL;

	return;
}

/*
 * @brief This function tests the my_atoi and my_itoa functions.
 *
 * @param none
 * @return void
 */
void conversion_test()
{
	uint8_t  *ptr;            /*data array pointer*/
	int32_t  startint = 4095; /*value to converter to ASCII then back to int*/
	int32_t  finalint;        /*integer value returned from atoi()*/
	uint32_t digits;          /*number of digits returned from itoa()*/

	printf("CONVERSION TEST\n");
	printf("  max value\n");

	/*allocate memory to data*/
	ptr = (uint8_t *) reserve_words(LENGTH_10);

	/*check for valid pointer*/
	if(ptr == NULL)
		printf("Fail: Null Pointer\n");
	else
		printf("Pass: Valid Pointer\n");

	/*display start value*/
  printf("start integer %d\n", startint);

	/*call itoa() and atoi() functions*/
  digits   = my_itoa(startint, ptr, BASE_10);
	finalint = my_atoi(ptr, digits, BASE_10);

	/*display final value*/
  printf("final integer %d\n", finalint);

	/*test for correct memmove operation*/
	if(startint == finalint)
		printf("Pass: Successful Conversion\n\n");
	else
		printf("Fail: Unsuccessful Reverse\n\n");

	/*free allocated memory*/
	free_words((uint32_t *) ptr);

	/*reset pointers*/
	ptr = NULL;

/******************************************************************************/
	/*converstion test with integer 0*/
	startint = 0; /*assign 0 be be converted*/

	printf("  zero value\n");

	/*allocate memory to data*/
	ptr = (uint8_t *) reserve_words(LENGTH_10);

	/*check for valid pointer*/
	if(ptr == NULL)
		printf("Fail: Null Pointer\n");
	else
		printf("Pass: Valid Pointer\n");

	/*display start value*/
  printf("start integer %d\n", startint);

	/*call itoa() and atoi() functions*/
  digits   = my_itoa(startint, ptr, BASE_10);
	finalint = my_atoi(ptr, digits, BASE_10);

	/*display final value*/
  printf("final integer %d\n", finalint);

	/*test for correct memmove operation*/
	if(startint == finalint)
		printf("Pass: Successful Conversion\n\n");
	else
		printf("Fail: Unsuccessful Reverse\n\n");

	/*free allocated memory*/
	free_words((uint32_t *) ptr);

	/*reset pointers*/
	ptr = NULL;

	return;
}

/*
 * @brief This function tests the swap_data_endianness function.
 *
 * @param none
 * @return void
 */
void endian_test()
{

	printf("ENDIAN TEST\n");

	int8_t ret;
	uint32_t data = 0x12345678;  /*data to be swapped*/
	uint32_t temp = data;        /*data to be determine successful swap*/

	/*display data to be pre-swap*/
	printf("B-L pre-swap:  %X\n", data);

	ret = swap_data_endianness((uint32_t *) &data, sizeof(data));

	/*display data to be post-swap*/
	printf("L-B post-swap: %X\n", data);

	/*display data to be pre-swap*/
	printf("L-B pre-swap:  %X\n", data);

	ret = swap_data_endianness((uint32_t *) &data, sizeof(data));

	/*display data to be post-swap*/
	printf("B-L post-swap: %X\n", data);

	/*test for correct swap operation*/
	if((ret == 0) && (data == temp))
		printf("Pass: Successful Swap\n\n");
	else
		printf("Fail: Unsuccessful Swap\n\n");

	return;
}

/*
 * @brief This function tests the circular buffer functions.
 *
 * @param none
 * @return void
 */
void buf_test()
{
	/*start of circular buffer test*/
	printf("CIRCULAR BUFFER TEST\n  a)full add, remove test\n\n");

	size_t length = LENGTH_8;       /*define the length of the buffer*/
	CB_t *buf;                    	/*declare buffer structure*/
	uint8_t data = 0xFF;
	uint8_t fail = 0;               /*flag to detect fail condition*/

	/*initialize the structure and buffer memory*/
	CB_init(&buf, length);

	/*check for valid pointer*/
	if(buf == NULL)
		printf("Fail: Null Pointer\n");
	else
		printf("Pass: Valid Pointer\n");

	/*check add and remvoe for the full length of the buffer*/
	for(uint8_t x = 0 ; x < length ; x++)
	{
		/*check propper addresses of head and tail*/
		if(buf->head_p != buf->tail_p)
			fail = 1;

		CB_buffer_add_item(buf, x);
		CB_buffer_remove_item(buf, x);

		/*check propper data in head and tail*/
		if(*(buf->head_p - 1) != *(buf->tail_p - 1))
			fail = 1;

		printf("head: %d\n", *(buf->head_p - 1));
		printf("tail: %d\n", *(buf->tail_p - 1));
	}

	if(fail == 0)
		printf("Pass: Full Length Add, Remove\n\n");
	else
		printf("Fail: Full Length Add, Remove\n\n");

	fail = 0;

/******************************************************************************/
	/*start of check full test*/
	printf("  b)check full test\n\n");

	CB_e status;       /*declare status enumeration*/

	/*fill the buffer*/
	for(uint8_t x = 0 ; x < length ; x++)
	{
		CB_buffer_add_item(buf, x);

		printf("head: %d\n", *(buf->head_p - 1));
	}

	status = CB_is_full(buf);

	if(status == (CB_e)CB_FULL_ERROR)
		printf("Pass: Buffer is full\n\n");
	else
		printf("Fail: Buffer is not full\n\n");

/******************************************************************************/
	/*start of check empty test*/
	printf("  c)check empty test\n\n");

	/*empty the buffer*/
	for(uint8_t x = 0 ; x < length ; x++)
	{
		CB_buffer_remove_item(buf, x);

		printf("tail: %d\n", *(buf->tail_p - 1));
	}

	status = CB_is_empty(buf);

	if(status == (CB_e)CB_EMPTY_ERROR)
		printf("Pass: Buffer is empty\n\n");
	else
		printf("Fail: Buffer is not empty\n\n");

/******************************************************************************/
	/*start of wrap add/remove test*/
	printf("  d)wrap add test\n\n");

	/*add and remove one at at time through the buffer twice*/
	for(uint8_t x = 0 ; x < LENGTH_16 ; x++)
	{
		CB_buffer_add_item(buf, x);
		CB_buffer_remove_item(buf, x);

		printf("head address of buf member %d: %p\n", ((8+x) % 8), (buf->head_p - 1));
		printf("tail address of buf member %d: %p\n", ((8+x) % 8), (buf->tail_p - 1));
	}

		printf("Verify successful rollover by observation\n\n");

/******************************************************************************/
	/*start of overfill test*/
	printf("  e)overfill test\n\n");

	/*overfill the buffer*/
	for(uint8_t x = 0 ; x < LENGTH_16 ; x++)
	{
		CB_buffer_add_item(buf, x);

		printf("head: %d\n", *(buf->head_p - 1));
		printf("head address: %p\n", (buf->head_p - 1));
	}

	/*verify head stops incrementing if buffer is full*/
	if(*(buf->head_p) != (*(buf->head_p -1)))
		printf("Pass: Buffer failed to overwrite data\n\n");
	else
		printf("Fail: Buffer overwrote data\n\n");

/******************************************************************************/
	/*start of over empty test*/
	printf("  e)over empty test\n\n");

	/*overfill the buffer*/
	for(uint8_t x = 0 ; x < LENGTH_16 ; x++)
	{
		CB_buffer_remove_item(buf, x);

		printf("tail: %d\n", *(buf->tail_p - 1));
		printf("tail address: %p\n", (buf->tail_p - 1));
	}

	/*verify tail stops incrementing if buffer is empty*/
	if(*(buf->tail_p) != (*(buf->tail_p -1)))
		printf("Pass: Buffer failed to remove empty data\n\n");
	else
		printf("Fail: Buffer removed empty data\n\n");

	return;
}

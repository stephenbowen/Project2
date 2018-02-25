/*
 * @file circbuf.c
 * @brief This file initializes and modifies a circular buffer
 *
 * @author Stephen Bowern
 * @date Feb 21, 2018
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "circbuf.h"

/*
 * @brief This function initializes a circular buffer
 *
 * This function initializes a cirular buffer by allocating the buffer structure
 * and allocating buffer memory. It takes in a pointer to the CB and the length
 * that the buffer should be. It returns the status of the buffer.
 *
 * @param CB_t **, size_t
 * @return CB_e (circular buffer enumeratoin)
 */
CB_e CB_init(CB_t **buf, size_t length)
{
	/*allocate buffer structure*/
	(*buf) = (CB_t *) malloc(sizeof(CB_t));

	if(*buf == NULL)
		return CB_NULL_PTR_ERROR;

	/*allocate buffer memory*/
	(*buf)->base_p = (uint8_t *) malloc(length * sizeof((*buf)->base_p));

	/*verify successful allocation*/
	if(*buf == NULL)
		return CB_NULL_PTR_ERROR;
 
	/*initialize length, count, head, and tail*/
	(*buf)->length = length;
	(*buf)->count  = 0;
	(*buf)->tail_p = (*buf)->base_p;
	(*buf)->head_p = (*buf)->base_p;

	return CB_NO_ERROR;
}

/*
 * @brief This function destroys a circular buffer
 *
 * This function destroys a circular buffer by deallocating the buffer memory
 * and the buffer structure. It takes in the buffer pointer and returns the
 * buffer status.
 *
 * @param CB_t *
 * @return CB_e (circular buffer enumeration)
 */
CB_e CB_destroy(CB_t **buf)
{
	if(*buf != NULL)
	{	
		/*free buffer memory*/
		free((void *) (*buf)->base_p);
		(*buf)->base_p = NULL;
	
		/*free structure memory*/
		free((void *) *buf);
		(*buf) = NULL;
	}

	return CB_NO_ERROR;
}

/*
 * @brief This function adds an item to the buffer.
 *
 * This function adds a data item to a circular buffer. It takes in a pointer to
 * the buffer and the data that is to be added. It returns the buffer status.
 *
 * @param CB_t *, uint8_t
 * @return CB_e (circular buffer enumeration)
 */
CB_e CB_buffer_add_item(CB_t *buf, uint8_t data)
{
	/*verify valid pointers*/
	if(! buf || ! buf->head_p || ! buf->base_p || ! buf->tail_p)
		return CB_NULL_PTR_ERROR;

	/*check if buffer is full*/
	if(buf->count == buf->length)
		return CB_FULL_ERROR;
	
	/*locate next free space*/
	if(buf->head_p == (buf->base_p + buf->length -1))
		buf->head_p = buf->base_p;

	/*set value into free space*/
	*buf->head_p = data;

	/*increment count*/
	buf->head_p++;
	buf->count++;

	return CB_NO_ERROR;
}

/*
 * @brief This function removes an item to the buffer.
 *
 * This function removes a data item from a circular buffer. It takes in a 
 * pointer to the buffer and a variable for the data that is to be removed. The
 * function returns the buffer status.
 *
 * @param CB_t *, uint8_t
 * @return CB_e (circular buffer enumeration)
 */
CB_e CB_buffer_remvoe_item(CB_t *buf, uint8_t data)
{
	/*verify valid pointers*/
	if(! buf || ! buf->head_p || ! buf->base_p || ! buf->tail_p)
		return CB_NULL_PTR_ERROR;
	
	/*check if tail is at the end of the buffer*/
	if(buf->tail_p == (buf->base_p + buf->length -1))
		buf->tail_p = buf->base_p;

	/*set value into free space*/
	data = *buf->tail_p;

	/*increment count*/
	buf->tail_p++;
	buf->count--;

	return CB_NO_ERROR;
}

/*
 * @brief This function checks if the buffer is full.
 *
 * This function checks if the circular buffer is full. It takes in the buffer
 * pointer and returns 'full' or 'not full' status.
 *
 * @param CB_t *
 * @return CB_e (circular buffer enumeration)
 */
CB_e CB_is_full(CB_t *buf)
{
	/*verify valid pointer*/
	if(buf == NULL)
		return CB_NULL_PTR_ERROR;

	/*check if buffer is full*/
	if(buf->count == buf->length)
		return CB_FULL_ERROR;
	else
		return BUFFER_NOT_FULL;
}

/*
 * @brief This function checks if the buffer is empty.
 *
 * This function checks if the circular buffer is empty. It takes in the buffer
 * pointer and returns 'empty' or 'not empty' status.
 *
 * @param CB_t *
 * @return CB_e (circular buffer enumeration)
 */
CB_e CB_is_empty(CB_t *buf)
{
	/*verify valid pointer*/
	if(buf == NULL)
		return CB_NULL_PTR_ERROR;

	/*check if buffer is empty*/
	if(buf->count == 0)
		return CB_EMPTY_ERROR;
	else
		return BUFFER_NOT_EMPTY;
}

/*
 * @brief This function peeks at a given data value.
 *
 * This function peeks at a given data value. It takes in the buffer pointer,
 * the data position to peek at, and a pointer to store the data that is peeked
 * at. The function returns the status of the buffer.
 *
 * @param CB_t *, size_t *, uint8_t
 * @return CB_e (circular buffer enumeration)
 */
CB_e CB_peek(CB_t *buf, size_t position, uint8_t *data)
{
	/*verify valid pointer*/
	if(buf == NULL)
		return CB_NULL_PTR_ERROR;

	*data = *(buf->base_p + position - 1);

	return CB_NO_ERROR;
}

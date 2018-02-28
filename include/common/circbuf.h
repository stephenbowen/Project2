/*
 * @file circbuf.h  
 * @brief This file is the header file for circbuf.c.
 *
 * @author Stephen Bowern
 * @date Feb 21, 2018
 */

#include <stdio.h>
#include <stdint.h>

#define BUFFER_NOT_FULL  0
#define BUFFER_NOT_EMPTY 0

/*Circular Buffer structure definition*/
typedef struct
{
	volatile uint8_t *base_p;  /*CB base pointer */
	volatile uint8_t *head_p;  /*CB head pointer */
	volatile uint8_t *tail_p;  /*CB tail pointer */
	volatile size_t length;    /*length of the CB*/
	volatile size_t count;     /*number of elements in the CB*/
} CB_t;

/*Circular Buffer status status enumberation definition*/
typedef enum
{
	CB_NO_ERROR       = 0,
	CB_NULL_PTR_ERROR = 1,
	CB_LENGTH_ERROR   = 1,
	CB_FULL_ERROR     = 1,
	CB_EMPTY_ERROR    = 1,
} CB_e;

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
CB_e CB_init(CB_t **, size_t);

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
CB_e CB_destroy(CB_t **);

/*
 * @brief This function adds an item to the buffer.
 *
 * This function adds a data item to a circular buffer. It takes in a pointer to
 * the buffer and the data that is to be added. It returns the buffer status.
 *
 * @param CB_t *, uint8_t
 * @return CB_e (circular buffer enumeration)
 */
CB_e CB_buffer_add_item(CB_t *, uint8_t);

/*
 * @brief This function removes an item t  *data = *(buf->base + position -1);
  ^
circbuf.c:197:17: error: ‘CB_t {aka struct <anonymous>}’ has no member named ‘base’; did you mean ‘base_p’?
o the buffer.
 *
 * This function removes a data item from a circular buffer. It takes in a 
 * pointer to the buffer and a variable for the data that is to be removed. The
 * function returns the buffer status.
 *
 * @param CB_t *, uint8_t
 * @return CB_e (circular buffer enumeration)
 */
CB_e CB_buffer_remvoe_item(CB_t *, uint8_t);

/*
 * @brief This function checks if the buffer is full.
 *
 * This function checks if the circular buffer is full. It takes in the buffer
 * pointer and returns 'full' or 'not full' status.
 *
 * @param CB_t *
 * @return CB_e (circular buffer enumeration)
 */
__attribute__((always_inline)) inline CB_e CB_is_full(CB_t *);

/*
 * @brief This function checks if the buffer is empty.
 *
 * This function checks if the circular buffer is empty. It takes in the buffer
 * pointer and returns 'empty' or 'not empty' status.
 *
 * @param CB_t *
 * @return CB_e (circular buffer enumeration)
 */
__attribute__((always_inline)) static inline CB_e CB_is_empty(CB_t *);

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
CB_e CB_peek(CB_t *, size_t, uint8_t *);

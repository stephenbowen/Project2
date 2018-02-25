/*
 * @file uart.c
 * @brief This file serves as the UART module for the project.
 *
 * @author Stephen Bowern
 * @date Feb 16, 2018
 */

#include <stdio.h>
#include <stdint.h>
#include "MKL25Z4.h"
#include "system_MKL25Z4.h"

/*
 * @brief This function configures the UART module.
 *
 * This function configures the UART registers to their appropriate values
 * for propper UART operation
 *
 * @param none
 * @return void
 */
void UART_configure(uint32_t baudrate)
{
	/*configure baud rate*/

	/*configure frame*/
	UART0->BDH |=
	UART0->BDH = UART0_BDH_SBR_MASK |= ;
	UART0->BDL = ;
}

/*
 * @brief This function transmits a byte of data.
 *
 * This function takes in an integer pointer to a bye of data. The function
 * transmits that single byte of data.
 *
 * @param uint8_t
 * @return void
 */
void UART_send(uint8_t *);

/*
 * @brief This function transmits n bytes of data.
 *
 * This function takes in an integer pointer to a bye of data and a number of 
 * bytes to transmit. The function transmits that number of bytes.
 *
 * @param uint8_t *, uint16_t
 * @return void
 */
void UART_send_n(uint8_t *, uint16_t);

/*
 * @brief This function receives a byte of data.
 *
 * This function takes in an integer pointer to a bye of data. The function
 * receives that single byte of data.
 *
 * @param uint8_t
 * @return void
 */
void UART_receive(uint8_t *);

/*
 * @brief This function receives n bytes of data.
 *
 * This function takes in an integer pointer to a bye of data and a number of 
 * bytes to receive. The function receives that number of bytes.
 *
 * @param uint8_t *, uint16_t
 * @return void
 */
void UART_receive_n(uint8_t *, uint16_t);

/*
 * @brief This function handles the Tx and Rx interrupts.
 *
 * This function takes no parameters and returns void. The function serves as
 * the intrrupt handler for the UART module. Interrupts include transmit
 * interrupts and receive interrupts.
 *
 * @param none
 * @return void
 */
void IRQHandler();

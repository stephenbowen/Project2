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
#include "uart.h"
#include "circbuf.h"

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
	/*activate UART0 clock*/
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;

	/*disable transmit and receive*/
	UART0_C2 &= ~UART0_C2_TE_MASK & ~UART0_C2_RE_MASK;

	/*set remaining control registers*/
	UART0_C1 = 0x00;    /*8 bit, no parity, others: don't care*/
	UART0_C3 = 0x00;
	UART0_C4 = 0x00;
	UART0_C5 = 0x00;    /*DMA disabled*/

	/*select clock source (FLL/PL)*/
	SIM_SOPT2 &= ~SIM_SOPT2_UART0SRC_MASK;
	SIM_SOPT2 |= SIM_SOPT2_UART0SRC(1);

	/*calculate baud rate divisor*/
	uint16_t divisor = (CLOCK_48MHZ / OVER_SAMPLE_16) / baudrate;
	/*configure over sample rate (OSR)*/
	UART0_C4 = UART0_C4_OSR(OVER_SAMPLE_16 - 1);

	/*set BR divisor into BDH and BDL registers*/
	UART0_BDH &= ~UART0_BDH_SBR_MASK;
	UART0_BDH |=  UART0_BDH_SBR(divisor);
	UART0_BDL &= ~UART0_BDL_SBR_MASK;
	UART0_BDL |=  UART0_BDL_SBR(divisor);

	/*enable UART transmit and receive*/
	UART0_C2 |= UART0_C2_TE_MASK | UART0_C2_RE_MASK;

	/*enable UART transmit and receive interrupts*/
	UART0_C2 |= UART0_C2_TIE_MASK | UART0_C2_RIE_MASK;

	return;
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
void UART_send(uint8_t *data)
{
	/*Wait until the tx buffer is empty, then put the data into the tx buffer
    for tranmit*/
	while((UART0_S1 & UART_S1_TDRE_MASK) == 0)
		;
	UART0_D = *data;

	return;
}

/*
 * @brief This function transmits n bytes of data.
 *
 * This function takes in an integer pointer to a bye of data and a number of 
 * bytes to transmit. The function transmits that number of bytes.
 *
 * @param uint8_t *, uint16_t
 * @return void
 */
void UART_send_n(uint8_t *data, uint16_t length)
{
	/*for each character, wait until the tx buffer is empty, then put the data
	  into the tx buffer for tranmit*/
	for(uint8_t i = 0 ; i < length ; i++)
	{
		while((UART0_S1 & UART_S1_TDRE_MASK) == 0)
			;

		UART0_D = *data;
		data++;
	}

	return;
}

/*
 * @brief This function receives a byte of data.
 *
 * This function takes in an integer pointer to a bye of data. The function
 * receives that single byte of data.
 *
 * @param uint8_t
 * @return void
 */
void UART_receive(uint8_t *data)
{
	/*for each character, wait until the rx buffer is filled. Then assign that
    value to the data register.*/

	while(CB_is_empty(rx_buf))
		;

	*data = UART0_D;

	return;
}

/*
 * @brief This function receives n bytes of data.
 *
 * This function takes in an integer pointer to a bye of data and a number of 
 * bytes to receive. The function receives that number of bytes.
 *
 * @param uint8_t *, uint16_t
 * @return void
 */
void UART_receive_n(uint8_t *data, uint16_t length)
{
	/*for each character, wait until the rx buffer is filled. Then assign that
    value to the data register.*/
	for(uint8_t i = length ; i > 0 ; i--)
	{
		while(CB_is_empty(rx_buf))
			;

		*data = UART0_D;
		data++;
	}

	return;
}

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
void IRQHandler()
{
	uint8_t status = UART0_S1;

	/*if the transmit interrupt has been enabled and the buffer is not empty,
    send the buffer data to the UART data register.*/
	if((status & UART0_S1_TDRE_MASK) && ! CB_is_empty(tx_buf))
	{
		UART0_D = UART_send(tx_buf);

		/*if the buffer is empty, clear the interrupt flag*/
		if(CB_is_empty(tx_buf))
			UART0_C2 &= ~UART_C2_TIE_MASK;
	}

	/*if the receive interrupt has been enabled and the buffer is not full,
    send the buffer data to the UART data register.*/
	if((status & UART0_S1_TDRE_MASK) && ! CB_is_empty(rx_buf))
	{
		UART_receive(rx_buf);

		/*if the buffer is full, clear the interrupt flag*/
		if(CB_is_full(rx_buf))
			UART0_C2 &= ~UART_C2_RIE_MASK;
	}

	return;
}

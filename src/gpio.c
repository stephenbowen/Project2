/*
 * @file gpio.c
 * @brief This file configures GPIO and toggles LEDs
 *
 * @author Stephen Bowern
 * @date Feb 24, 2018
 */

#include <stdio.h>
#include <stdint.h>
#include "gpio.h"
#include "MKL25Z4.h"
#include "bsp.h"

/*
 * @brief This function configures LED ports of the processor
 *
 * This function configures the LED ports of the processor to be ouputs and
 * initializes their values.
 *
 * @param none
 * @return void
 */
void GPIO_configure()
{
	/*enable clock gating*/
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;

	/*set LED pins to output*/
	GPIOB_PDDR |= (1 << GPIO_RED_OFFSET);
	GPIOB_PDDR |= (1 << GPIO_GREEN_OFFSET);
	GPIOD_PDDR |= (1 << GPIO_BLUE_OFFSET);
	
	/*set LED initial values to be on*/
	GPIOB_PSOR |= (1 << GPIO_RED_OFFSET);
	GPIOB_PSOR |= (1 << GPIO_GREEN_OFFSET);
	GPIOD_PSOR |= (1 << GPIO_BLUE_OFFSET);

	return;
}

/*
 * @brief This function toggles the state of the red LED.
 *
 * @param none
 * @return void
 */
void Toggle_Red_LED()
{
	GPIOB_PTOR |= (1 << GPIO_RED_OFFSET);

	return;
}

/*
 * @brief This function sets GPIO values
 *
 * This function sets GPIO values for a higher level toggle function. It takes
 * in the port to set, then sets that port.
 *
 * @param uint8_t
 * @return void
 */
void PORTB_Set(uint8_t bit_num)
{
	GPIOB_PSOR |= (1 << bit_num);

	return;
}

/*
 * @brief This function sets GPIO values
 *
 * This function sets GPIO values for a higher level toggle function. It takes
 * in the port to set, then sets that port.
 *
 * @param uint8_t
 * @return void
 */
void PORTD_Set(uint8_t bit_num)
{
	GPIOD_PSOR |= (1 << bit_num);

	return;
}

/*
 * @brief This function clears GPIO values
 *
 * This function clears GPIO values for a higher level toggle function. It takes
 * in the port to clear, then clears that port.
 *
 * @param uint8_t
 * @return void
 */
void PORTB_Clear(uint8_t bit_num)
{
	GPIOB_PCOR |= (1 << bit_num);

	return;
}

/*
 * @brief This function clears GPIO values
 *
 * This function clears GPIO values for a higher level toggle function. It takes
 * in the port to clear, then clears that port.
 *
 * @param uint8_t
 * @return void
 */
void PORTD_Clear(uint8_t bit_num)
{
	GPIOD_PCOR |= (1 << bit_num);

	return;
}

/*
 * @brief This function toggles GPIO values
 *
 * This function toggles GPIO values for a higher level toggle function. It
 * takes in the port to toggle, then togglese that port.
 *
 * @param uint8_t
 * @return void
 */
void PORTB_Toggle(uint8_t bit_num)
{
	GPIOB_PTOR |= (1 << bit_num);

	return;
}

/*
 * @brief This function toggles GPIO values
 *
 * This function toggles GPIO values for a higher level toggle function. It
 * takes in the port to toggle, then togglese that port.
 *
 * @param uint8_t
 * @return void
 */
void PORTD_Toggle(uint8_t bit_num)
{
	GPIOD_PTOR |= (1 << bit_num);

	return;
}

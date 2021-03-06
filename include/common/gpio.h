/*
 * @file gpio.h  
 * @brief This file is the header file for gpio.c.
 *
 * @author Stephen Bowern
 * @date Feb 16, 2018
 */

#include <stdio.h>
#include <stdint.h>
#include "MKL25Z4.h"

#define GPIO_RED_OFFSET   18
#define GPIO_GREEN_OFFSET 19
#define GPIO_BLUE_OFFSET   1

#define RGB_RED_PIN   (GPIOB + GPIO_RED_OFFSET)
#define RGB_GREEN_PIN (GPIOB + GPIO_GREEN_OFFSET)
#define RGB_BLUE_PIN  (BPIOD + GPIO_BLUE_OFFSET)

/*
 * @brief This function configures LED ports of the processor
 *
 * This function configures the LED ports of the processor to be ouputs and
 * initializes their values.
 *
 * @param none
 * @return void
 */
static inline void GPIO_configure();

/*
 * @brief This function toggles the state of the red LED.
 *
 * @param none
 * @return void
 */
static inline void Toggle_Red_LED();

/*
 * @brief This function sets GPIO values
 *
 * This function sets GPIO values for a higher level toggle function. It takes
 * in the port to set, then sets that port.
 *
 * @param uint8_t
 * @return void
 */
static inline void PORTB_Set(uint8_t);

/*
 * @brief This function sets GPIO values
 *
 * This function sets GPIO values for a higher level toggle function. It takes
 * in the port to set, then sets that port.
 *
 * @param uint8_t
 * @return void
 */
static inline void PORTD_Set(uint8_t);

/*
 * @brief This function clears GPIO values
 *
 * This function clears GPIO values for a higher level toggle function. It takes
 * in the port to clear, then clears that port.
 *
 * @param uint8_t
 * @return void
 */
static inline void PORTB_Clear(uint8_t);

/*
 * @brief This function clears GPIO values
 *
 * This function clears GPIO values for a higher level toggle function. It takes
 * in the port to clear, then clears that port.
 *
 * @param uint8_t
 * @return void
 */
static inline void PORTD_Clear(uint8_t);

/*
 * @brief This function toggles GPIO values
 *
 * This function toggles GPIO values for a higher level toggle function. It
 * takes in the port to toggle, then togglese that port.
 *
 * @param uint8_t
 * @return void
 */
static inline void PORTB_Toggle(uint8_t);

/*
 * @brief This function toggles GPIO values
 *
 * This function toggles GPIO values for a higher level toggle function. It
 * takes in the port to toggle, then togglese that port.
 *
 * @param uint8_t
 * @return void
 */
static inline void PORTD_Toggle(uint8_t);

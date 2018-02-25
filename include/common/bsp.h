/*
 * @file bsp.h
 * @brief This file contains macro definitions for LED toggle functions
 *
 * @author Stephen Bowern
 * @date Feb 24, 2018
 */

#include <stdio.h>
#include "MKL25Z4.h"

#define RGB_RED_ON ()       (PORTB_Set (RGB_RED_PIN))
#define RGB_RED_OFF ()      (PORTB_Clear (RGB_RED_PIN))
#define RGB_RED_TOGGLE ()   (PORTB_Toggle (RGB_RED_PIN))

#define RGB_GREEN_ON ()     (PORTB_Set (RGB_GREEN_PIN))
#define RGB_GREEN_OFF ()    (PORTB_Clear (RGB_GREEN_PIN))
#define RGB_GREEN_TOGGLE () (PORTB_Toggle (RGB_GREEN_PIN))

#define RGB_BLUE_ON ()      (PORTB_Set (RGB_BLUE_PIN))
#define RGB_BLUE_OFF ()     (PORTB_Clear (RGB_BLUE_PIN))
#define RGB_BLUE_TOGGLE ()  (PORTB_Toggle (RGB_BLUE_PIN))

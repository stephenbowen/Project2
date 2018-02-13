/*
  @file platform.h
  @brief This file is a header file for data.c

  The file defines a print statement only for the Beagle Bone and HOST systems.

  @author Stephen Bowern
  @date Feb 1, 2018
*/

#include <stdio.h>

/*define a print statement if the specified platform is 
  a host machine or the Beagle Bone Black board.
*/
#ifdef HOST
  #define PRINTF printf
#endif

#ifdef BBB
  #define PRINTF printf
#endif

#ifdef KL25Z
  #define PRINTF(x,...) (void)0

#else
  #define PRINTF(x,...) (void)0
#endif

/*
  @file main.c  
  @brief This file is used to call functions for testing.

  The file consists of one main() fucntion.  The fuction calls a predefined
  function for the purposes of testing.

  @author Stephen Bowern
  @date Feb 2, 2018
*/

#include <stdio.h>
#include "project1.h"

/*
  @brief This function calls other functions for the purpose of tesing.

  This main function simply calls other predifined functions.  The function is
  called if PROJECT1 is defined at compilation.  Otherwise, no function is
  called.

  @return int
*/
int main()
{
  #ifdef PROJECT1
    project1();
  #endif

  return 0;
}

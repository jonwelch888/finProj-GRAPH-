/*********************************************
* Name: Jon Welch
* Assignment: Final Project
* Purpose of the file: This source file contains the implementation of the random_range function.
* 
* @note This file is associated with [function.h]
*********************************************/

#include "function.h"
#include <cstdlib>

int random_range(int min, int max)
{
    /*********************************************
    * random_range: Function to generate a random integer within a specified range.
    * @param min : minimum value of the range
    * @param max : maximum value of the range
    * @return : random integer within the range [min, max]
    *********************************************/
    return (rand() % (max - min + 1)) + min;
}



/*********************************************
* Name: Jon Welch
* Assignment: Final Project
* Purpose of the file: This source file contains the implementation of the random_range function.
* 
* @note This file is associated with [function.h]
*********************************************/

#include "function.h"



bool compareVectors(const std::vector<int>& v1, const std::vector<int>& v2)
{
    /*********************************************
    * compareVectors: Function to compare two vectors of integers.
    * This function checks if two vectors are equal.
    *
    * @param v1 : const reference to the first vector of integers
    * @param v2 : const reference to the second vector of integers
    * @return : true if the vectors are equal, false otherwise
    *********************************************/
    return v1 == v2;
}

int random_range(int min, int max)
{
    /*********************************************
    * random_range: Function to generate a random integer within a specified range.
    * @param min : minimum value of the range
    * @param max : maximum value of the range
    * @return : random integer within the range [min, max]
    * @throws : std::invalid_argument if min is greater than max
    *********************************************/
    if (min > max)
    {
        throw std::invalid_argument("min cannot be greater than max");
    }
    return (rand() % (max - min + 1)) + min;
}


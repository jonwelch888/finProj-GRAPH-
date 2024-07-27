/***************************************************
* Name: Jon Welch
* Assignment: Final Project
* Purpose of the file: This header file declares extra helper function for testing; 
* 
* @note This file is associated with [function.cpp], & [main.cpp];
****************************************************/

#include <stdexcept>
#include <stdlib.h> /* rand */
#include <vector>
#include <algorithm>

#ifndef FUNCTION_H
#define FUNCTION_H

bool compareVectors(const std::vector<int>&, const std::vector<int>&);

int random_range(int, int);

#endif //FUNCTION_H

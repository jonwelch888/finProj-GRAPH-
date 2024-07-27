/***************************************************
* Name: Jon Welch
* Assignment: Final Project
* Purpose of the file: This header file declares extra helper function for testing; 
* 
* @note This file is associated with [function.cpp], & [main.cpp];
****************************************************/
#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdexcept>
#include <stdlib.h> /* rand */
#include <vector>
#include <algorithm>

using std::vector;



bool compareVectors(const vector<int>&, const vector<int>&);

int random_range(int, int);

#endif //FUNCTION_H

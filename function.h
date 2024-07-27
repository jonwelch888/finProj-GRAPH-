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

using std::vector;
using std::string;
using std::stack;
using std::queue;
using std::cout;
using std::endl;




#ifndef FUNCTION_H
#define FUNCTION_H

bool compareVectors(const vector<int>&, const vector<int>&);

int random_range(int, int);

#endif //FUNCTION_H

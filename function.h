/***************************************************
* Name: Jon Welch
* Assignment: Final Project
* Purpose of the file: This header file declares extra helper function for testing; 
* 
* @note This file is associated with [function.cpp], & [main.cpp];
****************************************************/
#ifndef FUNCTION_H
#define FUNCTION_H

#include <cmath> // for log function
#include <stdexcept>
#include <stdlib.h> /* rand */
#include <vector>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::vector;

int customMin(int, int);
int customMax(int, int);

void insertionSort(vector<int>&, int, int);
void merge(vector<int>&, int, int, int);
void tSort(vector<int>&, int);

bool compareVec(const vector<int>&, const vector<int>&);
int random_range(int, int);

#endif //FUNCTION_H

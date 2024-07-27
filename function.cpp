/*********************************************
* Name: Jon Welch
* Assignment: Final Project
* Purpose of the file: This source file contains the implementation of extra helper functions.
* 
* @note This file is associated with [function.h]
*********************************************/

#include "function.h"

int customMin(int a, int b)
{
    /*********************************************
    * customMin: Returns the minimum of two integers.
    * @param a : first integer
    * @param b : second integer
    * @return : minimum of a and b
    *********************************************/
    return (a < b) ? a : b;
}

int customMax(int a, int b)
{
    /*********************************************
    * customMax: Returns the maximum of two integers.
    * @param a : first integer
    * @param b : second integer
    * @return : maximum of a and b
    *********************************************/    
    return (a > b) ? a : b;
}

void insertionSort(vector<int>& arr, int start, int end)
{
    /*********************************************
    * insertionSort: Sorts a subarray using insertion sort.
    * @param arr : reference to the array to sort
    * @param start : starting index of the subarray
    * @param end : ending index of the subarray
    *********************************************/
    for (int i = (start + 1); i <= (end); i++)
    {
        int temp = (arr[i]);
        int j = (i - 1);
        while (j >= (start) && (arr[j]) > (temp))
        {
            arr[j + 1] = (arr[j]);
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(vector<int>& arr, int start, int mid, int end)
{
    /*********************************************
    * merge: Merges two sorted subarrays into a single sorted subarray.
    * @param arr : reference to the array containing subarrays
    * @param start : starting index of the first subarray
    * @param mid : ending index of the first subarray and start of the second
    * @param end : ending index of the second subarray
    *********************************************/    
    int len1 = mid - start + 1, len2 = end - mid;
    vector<int> left(arr.begin() + start, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + end + 1);

    int i = 0;
    int j = 0;
    int k = start;

    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // copy remaining elements of left, if any
    while (i < len1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    // copy remaining elements of right, if any
    while (j < len2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void tSort(vector<int>& arr, int n)
{
    /*********************************************
    * tSort: Sorts an array using TimSort algorithm.
    * @param arr : reference to the array to sort
    * @param n : size of the array
    *********************************************/
    // Determine the minimum run size based on array length 
    int minRun = customMax(32, int(std::log2(n)) + 1); // Calculation for dynamic run length

    // Sort individual subarrays of size RUN or dynamically determined minRun
    for (int i = 0; i < n; i += minRun)
    {
        insertionSort(arr, i, customMin(i + minRun - 1, n - 1));
    }

    // Start merging from size minRun. Merge to form size 64, then 128, 256 and so on...
    for (int size = minRun; size < n; size = 2 * size)
    {
        for (int start = 0; start < n; start += 2 * size)
        {
            int mid = start + size - 1;
            int end = customMin(start + 2 * size - 1, n - 1);

            if (mid < end)
            {
                merge(arr, start, mid, end);
            }
        }
    }
}

bool compareVectors(const vector<int>& v1, const vector<int>& v2)
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

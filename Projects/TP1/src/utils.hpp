#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>

#include "van.hpp"
#include "order.hpp"

using namespace std;

// Parameter to be used by the 'Sorter' class to sort the vans' vector
typedef enum VanSortParam_{
  MAX_VOLUME,
  MAX_WEIGHT,
  COST,
  MAX_WEIGHT_VOLUME
}VanSortParam;

// Parameter to be used by the 'Sorter' class to sort the orders' vector
typedef enum OrderSortParam_{
  VOLUME,
  WEIGHT,
  REWARD,
  DURATION,
  WEIGHT_VOLUME
}OrderSortParam;

/**
 * @brief Reads the data from the file containing each van's details and creates a new Van object
 * to be stored in an array.
 * @param filename The name of the file to be opened
 * @param vans The vector where the new Van object should be stored
 */
void getVanDetails(string filename, vector<Van> &vans);

/**
 * @brief Reads the data from the file containing each order's details and creates a new ORder object
 * to be stored in an array.
 * @param filename The name of the file to be opened
 * @param orders The vector where the new Order object should be stored
 */
void getOrderDetails(string filename, vector<Order> &orders);

/**
 * @brief The copy function is responsible for duplicating the values of each van's volume and 
 * weight in order to store them in a vector for each. This makes it so we have the original capacity
 * of each van and the current one (by changing the values in the given arrays).
 * 
 * @param vans The Vans vector to be acdessed
 * @param volumes The integer vector where all the volumes should be stored
 * @param weights The integer vector where all the weight should be stored
 */
void copy(const vector<Van> &vans, vector<int> &volumes, vector<int> &weights);

/**
 * @brief Prints a header followed by the contents of a vector.
 * @param vec Vector to be printed
 * @param header String to be printed first to introduce the vector printing
 */

template <class T>
void printVector(const vector<T> &vec, const string header);

/**
 * @brief Prints the correct usage of the command line whenever the input has too many or too few arguments.
 * @param command The name of the executable
 */
void usage(char* command);

/**
 * @brief Calculates the Standard Deviation of a set of integers.
 * @param data Integer vector to be used
 * @return The Standard Deviation value.
 */
float calculateSD(vector<int> data);

#endif
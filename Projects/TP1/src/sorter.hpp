#ifndef SORTER_HPP
#define SORTER_HPP

#include <iostream>
#include <vector>

#include "utils.hpp"
#include "van.hpp"
#include "order.hpp"

using namespace std;

class Sorter{
  public:
    /**
     * @brief Default constructor of the 'Sorter' class
     */
    Sorter();

    /**
     * @brief Sorting function used to sort the Vans vector.
     * @param vans Vans vector to be sorted
     * @param param Parameter to be used as the comparison value
     * @param ascending To decide whether the sorting should be ascending or not
     */
    static void sort(vector<Van> &vans, VanSortParam param, bool ascending);

    /**
     * @brief Sorting function used to sort the Orders vector.
     * @param vans Orders vector to be sorted
     * @param param Parameter to be used as the comparison value
     * @param ascending To decide whether the sorting should be ascending or not
     */
    static void sort(vector<Order> &orders, OrderSortParam param, bool ascending);
};


/**
 * @brief Decides which of the vans is larger.
 * @param v1 First van
 * @param v2 Second van
 * @return Returns true if the first van is larger than the second, false otherwise.
 */
bool sortVansByVolume(const Van &v1, const Van &v2);

/**
 * @brief Decides which of the vans is heavier.
 * @param v1 First van
 * @param v2 Second van
 * @return Returns true if the first van is heavier than the second, false otherwise.
 */
bool sortVansByWeight(const Van &v1, const Van &v2);

/**
 * @brief Decides which of the vans is more expensive.
 * @param v1 First van
 * @param v2 Second van
 * @return Returns true if the first van is more expensive than the second, false otherwise.
 */
bool sortVansByCost(const Van &v1, const Van &v2);

/**
 * @brief Decides which of the vans has more capacity.
 * @param v1 First van
 * @param v2 Second van
 * @return Returns true if the first van has more capacity than the second, false otherwise.
 */
bool sortVansByWeightAndVolume(const Van &v1, const Van &v2);

/**
 * @brief Decides which of the orders is larger.
 * @param o1 First order
 * @param o2 Second order
 * @return Returns true if the first order is larger than the second, false otherwise.
 */
bool sortOrdersByVolume(const Order &o1, const Order &o2);

/**
 * @brief Decides which of the orders is heavier.
 * @param o1 First order
 * @param o2 Second order
 * @return Returns true if the first order is heavier than the second, false otherwise.
 */
bool sortOrdersByWeight(const Order &o1, const Order &o2);

/**
 * @brief Decides which of the orders is more rewarding.
 * @param o1 First order
 * @param o2 Second order
 * @return Returns true if the first order is more rewarding than the second, false otherwise.
 */
bool sortOrdersByReward(const Order &o1, const Order &o2);

/**
 * @brief Decides which of the orders takes longer.
 * @param o1 First order
 * @param o2 Second order
 * @return Returns true if the first order takes longer than the second, false otherwise.
 */
bool sortOrdersByDuration(const Order &o1, const Order &o2);

/**
 * @brief Decides which of the orders has more capacity.
 * @param o1 First order
 * @param o2 Second order
 * @return Returns true if the first order has more capacity than the second, false otherwise.
 */
bool sortOrdersByWeightAndVolume(const Order &o1, const Order &o2);

#endif
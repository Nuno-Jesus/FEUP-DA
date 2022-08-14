#ifndef VAN_H
#define VAN_H

#include <iostream>
#include "order.hpp"

using namespace std;

class Van {
    public:
        /** 
         * @brief Default constructor for the 'Van' class 
         */
        Van();

        /**
         * @brief Overloaded constructor for the 'Van' class.
         * @param maxVolume Maximum volume able to transport
         * @param maxWeight Maximum weight able to transport
         * @param cost Cost to transport
         */
        Van(int maxVolume, int maxWeight, int cost);

        /**
         * @brief Checks if the van is unused by comparing its current capacity with the maximum
         * after attempting to pack orders.
         * @param weight The current unused weight of the van
         * @param volume The current unused volume of the van
         * @return Returns true if the van has the maximum capacity, false otherwise.
         */
        bool isUnused(const int &weight, const int &volume) const;
        
        /**
         * @brief Checks if the van is full by asserting for 0 volume/weight
         * @param weight The current unused weight of the van
         * @param volume The current unused volume of the van
         * @return Returns true if the van is capped on volume/weight, false otherwise.
         */
        bool isFull(const int &weight, const int &volume) const;

        /**
         * @brief Given the current volume and weight of a Van, it checks if an order is able to fit in that van.
         * @param volume The current volume of a van
         * @param weight The current weight of a van
         * @param order The order to be parsed
         * @return Returns true if the orders fits, false otherwise.
         */
        bool orderFits(const int volume, const int weight, const Order &order);

        /**
         * @brief Returns the content of the fields of the Van object in a string shaped return.
         * @return String assembled with the internal fields of the Van object
         */
        string toString() const;
        
        int getMaxVolume() const;
        int getMaxWeight() const;
        int getCost() const;

    private:
        int maxVolume;
        int maxWeight;
        int cost;
};

#endif
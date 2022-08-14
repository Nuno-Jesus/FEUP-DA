#ifndef ORDER_H
#define ORDER_H

#include <iostream>

using namespace std;

class Order {
    public:
        /** 
         * \brief Default constructor for the 'Order' class.
         */
        Order();

        /**
         * \brief Overloaded constructor for the 'Order' class.
         * \param maxVolume Maximum volume able to transport
         * \param maxWeight Maximum weight able to transport
         * \param reward cost to transport
         * \param duration duration of Order
         */
        Order(int volume, int weight, int reward, int duration);

        /**
         * @brief Returns the content of the fields of the Order object in a string shaped return.
         * @return String assembled with the internal fields of the Order object
         */
        string toString() const;
        
        int getVolume() const;
        int getWeight() const;
        int getReward() const;
        int getDuration() const;

    private:
        int volume;         // order volume
        int weight;         // order weight
        int reward;         // order reward
        int duration;       // order duration
};

#endif
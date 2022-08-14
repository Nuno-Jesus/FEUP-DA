#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>

#include "order.hpp"
#include "van.hpp"
#include "utils.hpp"
#include "sorter.hpp"

#define SECONDS_IN_WORK_DAY 28800
//#define DEBUG

using namespace std;

vector<Van> vans;
vector<Order> orders;
vector<int> orders_per_van;
vector<bool> order_is_used;

int numOrders;
int numVans;

double efficiency(){
  return (double) numOrders/orders.size();
}


/**
 * @brief //! Pack function for the 3rd scenario
 * @param seconds Total ammount of time spent delivering the orders
 */
void pack(double &seconds){
    size_t i = 0;
    while (seconds <= SECONDS_IN_WORK_DAY && i < orders.size()){
        seconds += orders.at(i).getDuration();
        numOrders++;
        i++;
    }
}


/**
 * @brief //! Pack function for the 2nd scenario
 * @param profit The total profit of the company (to be returned)
 */
void pack(int &profit){
    vector<int> weights(vans.size(), 0);
    vector<int> volumes(vans.size(), 0);

    copy(vans, volumes, weights);
    for(size_t i = 0; i < vans.size(); i++){
        int van_cost = vans.at(i).getCost();
        int orders_rewards = 0;

        //If we run out of orders
        if(find(order_is_used.begin(), order_is_used.end(), false) == order_is_used.end())
            break;

        for(size_t k = 0; k < orders.size(); k++){
            //If the order is already packed, parse the next order
            if(order_is_used.at(k)) continue;

            //If the van is full, stop packing
            else if(vans.at(i).isFull(weights.at(i), volumes.at(i))) break;

            //If the order fits in the van, pack it
            else if(vans.at(i).orderFits(volumes.at(i), weights.at(i), orders.at(k))){
                order_is_used.at(k) = true;
                volumes.at(i) -= orders.at(k).getVolume();
                weights.at(i) -= orders.at(k).getWeight();
                orders_rewards += orders.at(k).getReward();
                
                orders_per_van.at(i)++;
                numOrders++;
            }
        }

        //If the current van can't fit the order, no other van can: stop packing
        if(vans.at(i).isUnused(weights.at(i), volumes.at(i))) break;

        else if(profit > profit + orders_rewards - van_cost){
            numOrders -= orders_per_van.at(i);
            orders_per_van.at(i) = 0;
            break;
        }

        profit = profit + orders_rewards - van_cost;
        numVans++;
    }
}


/**
 * @brief //! Pack function for the 1st scenario
 */
void pack(){
    vector<int> weights(vans.size(), 0);
    vector<int> volumes(vans.size(), 0);

    copy(vans, volumes, weights);
    for(size_t i = 0; i < vans.size(); i++){
        //If we run out of orders
        if(find(order_is_used.begin(), order_is_used.end(), false) == order_is_used.end())
            break;

        for(size_t k = 0; k < orders.size(); k++){
            //If the order is already packed, parse the next order
            if(order_is_used.at(k)) continue;

            //If the van is full, stop packing
            else if(vans.at(i).isFull(weights.at(i), volumes.at(i))) break;

            //If the order fits in the van, pack it
            else if(vans.at(i).orderFits(volumes.at(i), weights.at(i), orders.at(k))){
                order_is_used.at(k) = true;
                volumes.at(i) -= orders.at(k).getVolume();
                weights.at(i) -= orders.at(k).getWeight();
                
                orders_per_van.at(i)++;
                numOrders++;
            }
        }

        //If the current van can't fit the order, no other van can: stop packing
        if(vans.at(i).isUnused(weights.at(i), volumes.at(i)))
            break;

        numVans++;
    }
}


/** 
 * @brief Scenario 1: Optimizing the number of delivery people needed
 * In this scenario we consider the possibility of delivering older orders in the next day.
 * Each van with at least 1 order packed, is considered in use
 */
void scenario1(){
    Sorter s;
    numVans = 0;
    numOrders = 0;

    orders_per_van.assign(vans.size(), 0);
    order_is_used.assign(orders.size(), false);

    s.sort(orders, WEIGHT_VOLUME, false);
    s.sort(vans, MAX_WEIGHT_VOLUME, false);

    cout << "\n\t/********************* Scenario 1 *********************/\n" << endl;
    for(int i = 1; i <= 2; i++){
        int previousVans = numVans;
        int previousOrders = numOrders;

        pack();

        cout << "DAY " << i << endl;
        cout << "-> Vans used: " << numVans - previousVans << endl;
        cout << "-> Orders delivered: " << numOrders - previousOrders << endl;
        cout << "-> Orders in the warehouse: " << (int)orders.size() - numOrders << endl;
        cout << "-> Company's efficiency: " << setprecision(3) << efficiency() * 100 << "%" << endl;
        cout << "-> Standard Deviation: " << setprecision(6) << calculateSD(orders_per_van) << endl;
        cout << endl;
    }
}


/**
 * @brief Scenario 2: Optimizing the company's profit.
 * - For each delivered order the company receives a reward for it
 * - For each van used on the transport, the company has to pay a fee for using it
 */
void scenario2(){
    Sorter s;
    int profit = 0;
    numVans = 0;
    numOrders = 0;

    orders_per_van.assign(vans.size(), 0);
    order_is_used.assign(orders.size(), false);

    s.sort(orders, REWARD, false);
    s.sort(vans, COST, true);

    pack(profit);

    cout << "\n\t/********************* Scenario 2 *********************/\n" << endl;
    cout << "-> Company's profit: " << profit << "€" << endl;
    cout << "-> Vans used: " << numVans << endl;
    cout << "-> Orders delivered: " << numOrders << endl;
    cout << "-> Orders in the warehouse: " << (int)orders.size() - numOrders << endl;
    cout << "-> Company's efficiency: " << setprecision(3) << efficiency() * 100 << "%" << endl;
    cout << "-> Standard Deviation: " << setprecision(3) << calculateSD(orders_per_van) << endl;
    cout << endl;
}


/** 
 * @brief Scenario 3: Minimize medium time needed to delivery express orders
 * - There is only one van that can only carry one order at a time, regardless weight or volume
 * - Delivery time is from 09:00 to 17:00
 * - Should maximize the number of orders, while minimizing the medium delivery time
 */
void scenario3(){
    Sorter s;
    double seconds = 0;
    numOrders = 0;

    order_is_used.assign(orders.size(), false);

    s.sort(orders, DURATION, true);
    pack(seconds);

    cout << "\n\t/********************* Scenario 3 *********************/\n" << endl;
    cout << "-> Numbers of express orders delivered: " << numOrders << endl;
    cout << "-> Orders in the warehouse: " << (int)orders.size() - numOrders << endl;
    cout << "-> Average time to deliver: " << round(seconds/numOrders) << " seconds" << endl;
    cout << "-> Company's efficiency: " << setprecision(3) << efficiency() * 100 << "%" << endl;
    cout << endl;
}

int main(int argc, char** argv){
    if(argc != 3)
        usage(argv[0]);

    for (int i = 1; i < argc; i++){
        if (atoi(argv[i]) < 1 || atoi(argv[i]) > 3){
            printf("Invalid dataset number, exiting...\n");
            exit(EXIT_FAILURE);
        }
    }

    string vans_number(argv[1]);
    string orders_number(argv[2]);

    string vans_file = "../input/carrinhas" + vans_number + ".txt";
    string orders_file = "../input/encomendas" + orders_number + ".txt";

    getVanDetails(vans_file, vans);
    getOrderDetails(orders_file, orders);

    #ifdef DEBUG
        printVector<Van>(vans, "\n\tVans: index -> maxVolume maxWeight cost\n\n");
        printVector<Order>(orders, "\n\tOrders: index -> volume weight reward duration(s)\n\n");
    #endif

    scenario1();
    scenario2();
    scenario3();

    return EXIT_SUCCESS;
}

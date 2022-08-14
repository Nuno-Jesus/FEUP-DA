#include <iostream>
#include "van.hpp"

using namespace std;


Van :: Van(){

}

Van :: Van(int maxVolume, int maxWeight, int cost){
    this->maxVolume = maxVolume;
    this->maxWeight = maxWeight;
    this->cost = cost;
}

bool Van :: isUnused(const int &weight, const int &volume) const{
    return (maxVolume == volume && maxWeight == weight);
}

bool Van :: isFull(const int &weight, const int &volume) const{
    return (weight == 0 || volume == 0);
}

bool Van :: orderFits(const int volume, const int weight, const Order &order){
    return (volume - order.getVolume() > 0 && weight - order.getWeight() > 0);
}

string Van :: toString() const{
    return to_string(maxVolume) + " " + to_string(maxWeight) + " " + to_string(cost) + "\n";
}

int Van :: getMaxVolume() const {
    return maxVolume;
}

int Van :: getMaxWeight() const {
    return maxWeight;
}

int Van :: getCost() const {
    return cost;
}





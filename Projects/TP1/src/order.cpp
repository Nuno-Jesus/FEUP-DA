#include <iostream>
#include "order.hpp"

Order :: Order(){

}

Order :: Order(int volume, int weight, int reward, int duration){
    this->volume = volume;
    this->weight = weight;
    this->reward = reward;
    this->duration = duration;
}

string Order :: toString() const{
    return to_string(volume) + " " + to_string(weight) + " " + to_string(reward) + " " + to_string(duration) + "\n";
}

int Order :: getVolume() const{ 
    return volume;
}

int Order :: getWeight() const{
    return weight;
}

int Order :: getReward()const {
    return reward;
}

int Order :: getDuration() const{
    return duration;
}
#include <iostream>
#include <algorithm>
#include "sorter.hpp"

using namespace std;

Sorter :: Sorter(){

}

//! ---------------------- VANS SORTING ---------------------- 

void Sorter :: sort(vector<Van> &vans, VanSortParam param, bool ascending){
  switch(param){
    case MAX_VOLUME:
      std::sort(vans.begin(), vans.end(), sortVansByVolume);
      break;
      
    case MAX_WEIGHT:
      std::sort(vans.begin(), vans.end(), sortVansByWeight);
      break;
    
    case COST:
      std::sort(vans.begin(), vans.end(), sortVansByCost);
      break;

    case MAX_WEIGHT_VOLUME:
      std::sort(vans.begin(), vans.end(), sortVansByWeightAndVolume);

    default:
      break;
  }

  if(ascending)
    std::reverse(vans.begin(), vans.end());
}

bool sortVansByVolume(const Van &v1, const Van &v2){
  return v1.getMaxVolume() > v2.getMaxVolume();
}

bool sortVansByWeight(const Van &v1, const Van &v2){
  return v1.getMaxWeight() > v2.getMaxWeight();
}

bool sortVansByCost(const Van &v1, const Van &v2){
  return v1.getCost() > v2.getCost();
}

bool sortVansByWeightAndVolume(const Van &v1, const Van &v2){
  if(v1.getMaxWeight() + v1.getMaxVolume() == v2.getMaxWeight() + v2.getMaxVolume())
    return abs(v1.getMaxWeight() - v1.getMaxVolume()) < abs((v2.getMaxWeight() - v2.getMaxVolume()));

  return (v1.getMaxWeight() + v1.getMaxVolume()) > (v2.getMaxWeight() + v2.getMaxVolume());
}

//! ---------------------- ORDERS SORTING ---------------------- 

void Sorter :: sort(vector<Order> &orders, OrderSortParam param, bool ascending){
  switch(param){
    case VOLUME:
      std::sort(orders.begin(), orders.end(), sortOrdersByVolume);
      break;
      
    case WEIGHT:
      std::sort(orders.begin(), orders.end(), sortOrdersByWeight);
      break;
    
    case REWARD:
      std::sort(orders.begin(), orders.end(), sortOrdersByReward);
      break;

    case DURATION:
      std::sort(orders.begin(), orders.end(), sortOrdersByDuration);
      break;

    case WEIGHT_VOLUME:
      std::sort(orders.begin(), orders.end(), sortOrdersByWeightAndVolume);
      break;

    default:
      break;
  }

  if(ascending)
    reverse(orders.begin(), orders.end());
}

bool sortOrdersByVolume(const Order &o1, const Order &o2){
  return o1.getVolume() > o2.getVolume();
}

bool sortOrdersByWeight(const Order &o1, const Order &o2){
  return o1.getWeight() > o2.getWeight();
}

bool sortOrdersByReward(const Order &o1, const Order &o2){
  return o1.getReward() > o2.getReward();
}

bool sortOrdersByDuration(const Order &o1, const Order &o2){
  return o1.getDuration() > o2.getDuration();
}

bool sortOrdersByWeightAndVolume(const Order &o1, const Order &o2){
  if(o1.getWeight() + o1.getVolume() == o2.getWeight() + o2.getVolume())
    return abs(o1.getWeight() - o1.getVolume()) < abs((o2.getWeight() - o2.getVolume()));

  return (o1.getWeight() + o1.getVolume()) > (o2.getWeight() + o2.getVolume());
}

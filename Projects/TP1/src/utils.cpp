#include <iostream>
#include "utils.hpp"
#include "order.hpp"
#include "van.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

void getVanDetails(string filename, vector<Van> &vans){
    ifstream file(filename);
    string line;
    int maxVolume, maxWeight, cost;

    if (file.fail()){
        cout << "Error while reading from: " << filename << endl << "Exiting..." << endl;
        exit(1);
    }

    getline(file, line);

    while(getline(file, line)){
        istringstream is(line);

        is >> maxVolume >> maxWeight >> cost;
        Van Van(maxVolume, maxWeight, cost);
        vans.push_back(Van);
    }
}

void getOrderDetails(string filename, vector<Order> &orders){
    ifstream file(filename);
    string line;
    int volume, weight, reward, duration;

    if (file.fail()){
        cout << "Error while reading from " << filename << endl << "Exiting..." << endl;
        exit(1);
    }

    getline(file, line);

    while(getline(file, line)){
        istringstream is(line);
        is >> volume >> weight >> reward >> duration;

        Order Order(volume, weight, reward, duration);
        orders.push_back(Order);
    }
}

void copy(const vector<Van> &vans, vector<int> &volumes, vector<int> &weights){
    for(size_t i = 0; i < vans.size(); i++){
        volumes.at(i) = vans.at(i).getMaxVolume();
        weights.at(i) = vans.at(i).getMaxWeight();
    }
}

template<class T>
void printVector(const vector<T> &vec, const string header){
    cout << header;

    int k = 0;
    for (auto curr : vec)
        cout << k++ << " -> " << curr.toString();
}

template void printVector<Van>(const vector<Van> &vec, const string header);
template void printVector<Order>(const vector<Order> &vec, const string header);


void usage(char* command){
    cout << "Usage: " << command << " vans_file_number orders_file_number" << endl;
    exit(EXIT_FAILURE);
}

float calculateSD(vector<int> data) {
    float sum = 0.0, mean, SD = 0.0;
    int limit = (int)data.size() < 10 ? (int)data.size() : 10;
    int i;

    for (i = 0; i < limit; ++i) {
        sum += data.at(i);
    }

    mean = sum / 10;
    for (i = 0; i < limit; ++i) {
        SD += pow(data.at(i) - mean, 2);
    }
    
    return sqrt(SD / 10);
}
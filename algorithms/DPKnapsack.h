//
// Created by deniz on 5/19/2025.
//

#ifndef DPKNAPSACK_H
#define DPKNAPSACK_H
#include <vector>


void dpKnapsack(int capacity, const std::vector<int> &weights, const std::vector<int> &values, int &bestValue,
                std::vector<int> &selectedItems);


#endif //DPKNAPSACK_H

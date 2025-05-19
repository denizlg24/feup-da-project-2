//
// Created by deniz on 5/19/2025.
//

#ifndef GREEDYKNAPSACK_H
#define GREEDYKNAPSACK_H
#include <vector>


void greedyKnapsack(int capacity,
                         const std::vector<int> &weights,
                         const std::vector<int> &values,
                         int &totalValue,
                         std::vector<int> &selectedItems);


#endif //GREEDYKNAPSACK_H

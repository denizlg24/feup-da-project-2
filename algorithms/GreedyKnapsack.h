//
// Created by deniz on 5/19/2025.
//

#ifndef GREEDYKNAPSACK_H
#define GREEDYKNAPSACK_H
#include <vector>

/**
 * @brief Solves the fractional Knapsack problem using a greedy approach.
 *
 * @param capacity The maximum weight capacity of the knapsack.
 * @param weights A vector containing the weights of the items.
 * @param values A vector containing the values of the items.
 * @param totalValue Reference to an integer where the total value of the selected items will be stored.
 * @param selectedItems Reference to a vector where the indices of selected items will be stored.
 */
void greedyKnapsack(int capacity,
                         const std::vector<int> &weights,
                         const std::vector<int> &values,
                         int &totalValue,
                         std::vector<int> &selectedItems);


#endif //GREEDYKNAPSACK_H

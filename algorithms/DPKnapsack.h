//
// Created by deniz on 5/19/2025.
//

#ifndef DPKNAPSACK_H
#define DPKNAPSACK_H
#include <vector>

/**
 * @brief Solves the 0/1 Knapsack problem using dynamic programming.
 *
 * @param capacity The maximum weight capacity of the knapsack.
 * @param weights A vector containing the weights of the items.
 * @param values A vector containing the values of the items.
 * @param bestValue Reference to an integer where the maximum total value will be stored.
 * @param selectedItems Reference to a vector where the indices of selected items will be stored.
 */
void dpKnapsack(int capacity, const std::vector<int> &weights, const std::vector<int> &values, int &bestValue,
                std::vector<int> &selectedItems);


#endif //DPKNAPSACK_H

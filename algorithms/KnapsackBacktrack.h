//
// Created by deniz on 5/13/2025.
//

#ifndef KNAPSACKBACKTRACK_H
#define KNAPSACKBACKTRACK_H
#include <vector>

/**
 * @brief Solves the 0/1 Knapsack problem using a backtracking approach.
 *
 * @param weights A vector containing the weights of the items.
 * @param values A vector containing the values of the items.
 * @param capacity The maximum weight capacity of the knapsack.
 * @param index The current item index being considered.
 * @param currentWeight The total weight of the currently selected items.
 * @param currentValue The total value of the currently selected items.
 * @param currentSolution A vector representing the current selection of items (by indices).
 * @param maxValue Reference to an integer storing the best (maximum) value found so far.
 * @param minWeight Reference to an integer storing the weight of the best-value solution (used for tie-breaking).
 * @param bestSolution Reference to a vector storing the best item selection found.
 */
void backtrack(const std::vector<int> &weights, const std::vector<int> &values, int capacity,
               int index, int currentWeight, int currentValue, std::vector<int> &currentSolution, int &maxValue, int& minWeight,
               std::vector<int> &bestSolution);


#endif //KNAPSACKBACKTRACK_H

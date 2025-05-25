//
// Created by deniz on 5/19/2025.
//

#ifndef GREEDYKNAPSACKCOMMAND_H
#define GREEDYKNAPSACKCOMMAND_H
#include "Command.h"

/**
 * @class GreedyKnapsackCommand
 * @brief Command to solve the Knapsack problem using a greedy heuristic.
 *
 * This class implements the Command interface and provides an approximate
 * solution to the 0/1 Knapsack problem by selecting items based on their
 * value-to-weight ratio. While not guaranteed to find the optimal solution,
 * this method is fast and often yields good results for large instances.
 */
class GreedyKnapsackCommand : public Command {
    /**
    * @brief Executes the greedy Knapsack algorithm.
    *
    * Retrieves the problem data (weights, values, capacity) from the context
    * and selects items greedily based on value-to-weight ratio. The selected
    * items and their total value are stored back in the context.
    *
    * @param context Pointer to the Context containing the problem data.
    * @param args A vector of strings representing any optional arguments (typically unused).
    */
    void execute(Context *context, std::vector<std::string> args) override;
};


#endif //GREEDYKNAPSACK_H

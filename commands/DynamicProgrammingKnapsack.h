//
// Created by deniz on 5/19/2025.
//

#ifndef DYNAMICPROGRAMMINGKNAPSACK_H
#define DYNAMICPROGRAMMINGKNAPSACK_H
#include "Command.h"

/**
 * @class DynamicProgrammingKnapsack
 * @brief Command to solve the 0/1 Knapsack problem using dynamic programming.
 *
 * This class implements the Command interface and applies a bottom-up dynamic
 * programming approach to solve the Knapsack problem. It guarantees an optimal
 * solution by computing the maximum achievable value for each sub-capacity.
 */
class DynamicProgrammingKnapsack : public Command {
    /**
     * @brief Executes the dynamic programming Knapsack algorithm.
     *
     * Retrieves the problem instance (weights, values, capacity) from the context
     * and computes the optimal solution using a dynamic programming table.
     *
     * @param context Pointer to the Context containing the problem data.
     * @param args A vector of strings representing any optional arguments (typically unused).
     */
    void execute(Context *context, std::vector<std::string> args) override;
};


#endif //DYNAMICPROGRAMMINGKNAPSACK_H

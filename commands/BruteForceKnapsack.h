//
// Created by deniz on 5/13/2025.
//

#ifndef BRUTEFORCEKNAPSACK_H
#define BRUTEFORCEKNAPSACK_H
#include "Command.h"

/**
 * @class BruteForceKnapsack
 * @brief Implements the brute-force approach to solve the 0/1 Knapsack problem.
 *
 * This class derives from the Command interface and overrides the execute method
 * to evaluate all possible combinations of items to find the optimal selection
 * that maximizes value without exceeding the knapsack's capacity.
 */
class BruteForceKnapsack : public Command  {
    /**
    * @brief Executes the brute-force Knapsack algorithm using context and input arguments.
    *
    * @param context Pointer to the Context containing shared application state.
    * @param args A vector of strings containing any additional arguments required by the command.
    */
    void execute(Context *context, std::vector<std::string> args) override;
};



#endif //BRUTEFORCEKNAPSACK_H

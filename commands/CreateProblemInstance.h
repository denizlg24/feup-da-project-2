//
// Created by deniz on 5/9/2025.
//

#ifndef CREATEPROBLEMINSTANCE_H
#define CREATEPROBLEMINSTANCE_H
#include "Command.h"

/**
 * @class CreateProblemInstance
 * @brief Command to initialize a new 0/1 Knapsack problem instance.
 *
 * This class implements the Command interface and is responsible for creating
 * a new problem instance by reading item weights, values, and knapsack capacity
 * from the csv files. The generated data is stored in the
 * shared application context for use by other commands.
 */
class CreateProblemInstance : public Command {
    /**
     * @brief Executes the creation of a new problem instance.
     *
     * This method sets up a new Knapsack problem by populating the context
     * with necessary data such as item weights, values, and the capacity
     * of the knapsack.
     *
     * @param context Pointer to the Context that holds application state and problem data.
     * @param args A vector of strings representing the arguments needed to create the instance.
     */
    void execute(Context *context, std::vector<std::string> args) override;
};


#endif //CREATEPROBLEMINSTANCE_H

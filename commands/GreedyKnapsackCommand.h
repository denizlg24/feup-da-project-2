//
// Created by deniz on 5/19/2025.
//

#ifndef GREEDYKNAPSACKCOMMAND_H
#define GREEDYKNAPSACKCOMMAND_H
#include "Command.h"


class GreedyKnapsackCommand : public Command {
    void execute(Context *context, std::vector<std::string> args) override;
};


#endif //GREEDYKNAPSACK_H

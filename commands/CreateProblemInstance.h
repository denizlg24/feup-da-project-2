//
// Created by deniz on 5/9/2025.
//

#ifndef CREATEPROBLEMINSTANCE_H
#define CREATEPROBLEMINSTANCE_H
#include "Command.h"


class CreateProblemInstance : public Command {
    void execute(Context *context, std::vector<std::string> args) override;
};


#endif //CREATEPROBLEMINSTANCE_H

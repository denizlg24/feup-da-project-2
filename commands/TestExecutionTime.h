//
// Created by deniz on 5/20/2025.
//

#ifndef TESTEXECUTIONTIME_H
#define TESTEXECUTIONTIME_H
#include "Command.h"


class TestExecutionTime : public Command {
    void execute(Context *context, std::vector<std::string> args) override;
};



#endif //TESTEXECUTIONTIME_H

//
// Created by deniz on 5/20/2025.
//

#ifndef HELP_H
#define HELP_H
#include "Command.h"


class Help: public Command {
    void execute(Context *context, std::vector<std::string> args) override;
};



#endif //HELP_H

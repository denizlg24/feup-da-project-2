//
// Created by deniz on 5/20/2025.
//

#ifndef HELP_H
#define HELP_H
#include "Command.h"

/**
 * @class Help
 * @brief Command that displays available commands and their usage.
 *
 * This class implements the Command interface and provides help information
 * to the user, listing all supported commands and optionally giving usage
 * instructions for a specific command if requested.
 */
class Help : public Command {
    /**
    * @brief Displays help information.
    *
    * If no arguments are provided, this method prints a list of all available
    * commands.
    *
    * @param context Pointer to the Context containing application state (unused).
    * @param args A vector of strings containing optional arguments.
    */
    void execute(Context *context, std::vector<std::string> args) override;
};


#endif //HELP_H

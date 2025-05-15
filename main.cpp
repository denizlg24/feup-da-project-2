#include "cli/CLI.h"
#include "cli/CommandRegistry.h"
#include "commands/BruteForceKnapsack.h"
#include "commands/CreateProblemInstance.h"
#include "commands/ReadFromFile.h"

int main(int argc, char *argv[]) {
    auto *registry = new CommandRegistry();
    registry->getContext()->set("registry", registry);
    registry->registerCommand("read_from_file", new ReadFromFile());
    registry->registerCommand("create_problem", new CreateProblemInstance());
    registry->registerCommand("brute_force", new BruteForceKnapsack());
    registry->registerDependency("brute_force", "create_problem");
    CLI::run(*registry);
    return 0;
}

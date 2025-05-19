#include "cli/CLI.h"
#include "cli/CommandRegistry.h"
#include "commands/BruteForceKnapsack.h"
#include "commands/CreateProblemInstance.h"
#include "commands/DynamicProgrammingKnapsack.h"
#include "commands/GreedyKnapsackCommand.h"
#include "commands/ReadFromFile.h"

int main(int argc, char *argv[]) {
    auto *registry = new CommandRegistry();
    registry->getContext()->set("registry", registry);
    registry->registerCommand("read_from_file", new ReadFromFile());
    registry->registerCommand("create_problem", new CreateProblemInstance());
    registry->registerCommand("brute_force", new BruteForceKnapsack());
    registry->registerCommand("dynamic_programming", new DynamicProgrammingKnapsack());
    registry->registerCommand("greedy", new GreedyKnapsackCommand());
    registry->registerDependency("brute_force", "create_problem");
    registry->registerDependency("dynamic_programming", "create_problem");
    registry->registerDependency("greedy", "create_problem");
    CLI::run(*registry);
    return 0;
}

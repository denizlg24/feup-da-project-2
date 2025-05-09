

#include "cli/CLI.h"
#include "cli/CommandRegistry.h"
#include "commands/CreateProblemInstance.h"
#include "commands/ReadFromFile.h"

int main(int argc, char* argv[]) {
    auto *registry = new CommandRegistry();
    registry->getContext()->set("registry",registry);
    registry->registerCommand("read_from_file", new ReadFromFile());
    registry->registerCommand("create_problem", new CreateProblemInstance());
    CLI::run(*registry);
    return 0;
}

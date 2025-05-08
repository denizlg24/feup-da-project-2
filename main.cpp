

#include "cli/CLI.h"
#include "cli/CommandRegistry.h"

int main(int argc, char* argv[]) {
    auto *registry = new CommandRegistry();
    registry->getContext()->set("registry",registry);
    CLI::run(*registry);
    return 0;
}

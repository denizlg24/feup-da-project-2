//
// Created by deniz on 5/20/2025.
//

#include "Help.h"

void Help::execute(Context *context, std::vector<std::string> args) {
    cout << "===== HELP =====" << endl;
    cout << endl;
    cout << "help --> Displays a list of available commands." << endl;
    cout << endl;
    cout << "commands --> Displays a list of available commands." << endl;
    cout << endl;
    cout << "exit --> Exits program." << endl;
    cout << endl;
    cout <<
            "create_problem <TruckAndPallets> <Pallets> --> Reads a csv file from filename and creates and instance of the knapsack 0/1 problem."
            << endl;
    cout << endl;
    cout << "brute_force --> Uses a bruteforce solution for the problem instance" << endl;
    cout << endl;
    cout << "dynamic_programming --> Uses a dynamic programming solution for the problem instance" << endl;
    cout << endl;
    cout << "greedy --> Uses a greedy approach to approximate the solution" << endl;
    cout << endl;
    cout << "test_solution <solution> <n times> --> Runs the solution n times to get average execution times" << endl;
    cout << endl;
    cout << "read_from_file <input> <output> --> Reads commands from <input> and places results inside <output>" <<
            endl;
}

//
// Created by deniz on 3/18/2025.
//

#include "CLI.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void CLI::run(CommandRegistry &registry) {
    std::string input;
    while (true) {
        std::cout << "DA24/25 > ";
        std::getline(std::cin, input);
        if (input.empty()) continue;
        if (input == "exit" || input == "quit") break;

        std::istringstream iss(input);
        vector<std::string> tokens;
        std::string token;
        while (iss >> token) {
            tokens.push_back(token);
        }

        if (!tokens.empty()) {
            registry.executeCommand(tokens[0], tokens);
        }
    }
}

void CLI::runFromFile(CommandRegistry *registry, const string &inputFile, const string &outputFile) {
    ifstream in(inputFile);
    if (!in) {
        cerr << "Error: Cannot open input file " << inputFile << endl;
        return;
    }

    ofstream out(outputFile);
    if (!out) {
        cerr << "Error: Cannot open output file " << outputFile << endl;
        return;
    }

    streambuf *coutBackup = cout.rdbuf(out.rdbuf());

    string line;
    int lineNumber = 1;
    while (getline(in, line)) {
        istringstream iss(line);
        string command;
        iss >> command;
        if (!command.empty()) {
            vector<string> args;
            args.push_back(command);
            string arg;
            while (getline(in, arg)) {
                lineNumber++;
                if (arg.empty()) {
                    break;
                } else {
                    args.push_back(arg);
                }
            }
            try {

                registry->executeCommand(command, args);
                cout << endl;
            } catch (const exception &e) {
                cout << "Error on line " << lineNumber << ": " << e.what() << endl;
            }
        }
        lineNumber++;
    }
    cout.rdbuf(coutBackup);
}

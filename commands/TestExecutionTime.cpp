//
// Created by deniz on 5/20/2025.
//

#include "TestExecutionTime.h"

#include <chrono>
#include "../algorithms/KnapsackBacktrack.h"
#include "../algorithms/DPKnapsack.h"
#include "../algorithms/GreedyKnapsack.h"
#include "../data_structures/TruckProblemInstance.h"
#include <numeric>

void testBacktrack(vector<double> &times, vector<int> &weights, vector<int> &values, int capacity) {
    int n = weights.size();
    vector<int> currentSolution(n, 0);
    int maxValue = 0;
    int minWeight = INT_MAX;
    vector<int> bestSolution;
    auto start = std::chrono::high_resolution_clock::now();
    backtrack(weights, values, capacity, 0, 0, 0, currentSolution, maxValue, minWeight, bestSolution);
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;
    times.push_back(duration.count());
}

void testDP(vector<double> &times, vector<int> &weights, vector<int> &values, int capacity) {
    vector<int> selectedItems;
    int bestValue = 0;
    auto start = std::chrono::high_resolution_clock::now();
    dpKnapsack(capacity, weights, values, bestValue, selectedItems);
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;
    times.push_back(duration.count());
}

void testGreedy(vector<double> &times, vector<int> &weights, vector<int> &values, int capacity) {
    vector<int> selectedItems;
    int bestValue = 0;
    auto start = std::chrono::high_resolution_clock::now();
    greedyKnapsack(capacity, weights, values, bestValue, selectedItems);
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;
    times.push_back(duration.count());
}

void TestExecutionTime::execute(Context *context, std::vector<std::string> args) {
    if (args.size() != 3) {
        if (args.size() == 2) {
            cout << "Correct usage --> test_solution <solution> <n times>, missing n times." << endl;
        }
        if (args.size() == 1) {
            cout << "Correct usage --> test_solution <solution> <n times>, missing solution and n times." << endl;
        }
        return;
    }
    try {
        const auto instance = context->get<TruckProblemInstance *>("instance");

        vector<int> weights = (*instance)->getWeights();
        vector<int> values = (*instance)->getProfits();
        int capacity = (*instance)->getCapacity();
        vector<double> times;

        if (args[1] == "brute_force") {
            for (int i = 0; i < stoi(args[2]); i++) {
                testBacktrack(times, weights, values, capacity);
            }
        }
        if (args[1] == "dynamic_programming") {
            for (int i = 0; i < stoi(args[2]); i++) {
                testDP(times, weights, values, capacity);
            }
        }
        if (args[1] == "greedy") {
            for (int i = 0; i < stoi(args[2]); i++) {
                testGreedy(times, weights, values, capacity);
            }
        }

        if (!times.empty()) {
            double sum = 0;
            for (const auto &n: times)
                sum += n;
            cout << "Ran the " << args[1] << " solution " << times.size() << " times." << endl;
            cout << "The average time of execution was t=" << sum / times.size() << endl;
        }
    } catch (...) {
    }
}

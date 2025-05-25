//
// Created by deniz on 5/13/2025.
//

#include "BruteForceKnapsack.h"

#include <chrono>

#include "../algorithms/KnapsackBacktrack.h"
#include "../cli/CLI.h"
#include "../cli/CommandRegistry.h"
#include "../data_structures/TruckProblemInstance.h"

void BruteForceKnapsack::execute(Context *context, std::vector<std::string> args) {
    try {
        const auto instance = context->get<TruckProblemInstance *>("instance");

        vector<int> weights = (*instance)->getWeights();
        vector<int> values = (*instance)->getProfits();
        int capacity = (*instance)->getCapacity();
        int n = weights.size();

        vector<int> currentSolution(n, 0);
        int maxValue = 0;
        int minWeight = INT_MAX;
        vector<int> bestSolution;
        auto start = std::chrono::high_resolution_clock::now();
        backtrack(weights, values, capacity, 0, 0, 0, currentSolution, maxValue, minWeight, bestSolution);
        auto end = std::chrono::high_resolution_clock::now();
        chrono::duration<double, std::milli> duration = end - start;
        int totalWeight = 0;
        for (int i = 0; i < n; ++i) {
            if (bestSolution[i]) {
                totalWeight += weights[i];
            }
        }
        cout << "Weight: " << totalWeight << endl;
        cout << "Profit: " << maxValue << endl;
        cout << "Selected items: ";
        for (int i = 0; i < n; ++i) {
            if (bestSolution[i]) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
        std::cout << "[INFO] Command executed in " << duration.count() << " ms\n";
    } catch (...) {
        cout << "Error getting registry from context." << endl;
    }
}
